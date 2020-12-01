## Tidb

`Tidb` 是开源分布式关系型数据库, 兼容 `MySQL 5.7` 协议和 `MySQL` 生态等重要特性。

## Table of contrents
+ 组件
    + [tidb](#tidb)
    + [tipd](#tipd)
    + [tikv](#tikv)
+ 手动部署
    + [容器部署](#容器部署)

## tidb
`SQL` 层，对外暴露 `MySQL` 协议的连接 `endpoint`，负责接受客户端的连接，执行 `SQL` 解析和优化，最终生成分布式执行计划。TiDB 层本身是无状态的。

## tipd
集群的元信息管理模块，负责存储每个 `TiKV` 节点实时的数据分布情况和集群的整体拓扑结构，同时还会根据 `TiKV` 节点实时上报的数据分布状态，下发数据调度命令给具体的 `TiKV` 节点，建议部署奇数个 `PD` 节点。

## tikv
`tikv` 负责存储数据，是一个分布式的提供事务的 `Key-Value` 存储引擎。`TiDB` 的 `SQL` 层做完 `SQL` 解析后，会将 `SQL` 的执行计划转换为对 `TiKV API` 的实际调用。所以，数据都存储在 `TiKV` 中。另外，`TiKV` 中的数据都会自动维护多副本（默认为三副本），天然支持高可用和自动故障转移。


## 容器部署

### 部署 TIPD
```bash
#! /usr/bin/env bash

sudo podman run -d --name pd \
  --ip 10.88.1.1 \
  -v /etc/localtime:/etc/localtime:ro \
  -v /var/lib/tidb:/data \
  pingcap/pd:latest \
  --name="pd" \
  --data-dir="/data/pd" \
  --client-urls="http://0.0.0.0:2379" \
  --advertise-client-urls="http://10.88.1.1:2379" \
  --peer-urls="http://0.0.0.0:2380" \
  --advertise-peer-urls="http://10.88.1.1:2380" \
  --initial-cluster="pd=http://10.88.1.1:2380"
```

### 部署 TIKV
```bash
#! /usr/bin/env bash

podman run -d --name tikv1 \
  --ip 10.88.1.11\
  -v /etc/localtime:/etc/localtime:ro \
  -v /var/lib/tidb:/data \
  pingcap/tikv:latest \
  --addr="0.0.0.0:20160" \
  --advertise-addr="10.88.1.11:20160" \
  --data-dir="/data/tikv1" \
  --pd="10.88.1.1:2379"

podman run -d --name tikv2 \
  --ip 10.88.1.12\
  -v /etc/localtime:/etc/localtime:ro \
  -v /var/lib/tidb:/data \
  pingcap/tikv:latest \
  --addr="0.0.0.0:20160" \
  --advertise-addr="10.88.1.12:20160" \
  --data-dir="/data/tikv2" \
  --pd="10.88.1.1:2379"

podman run -d --name tikv3 \
  --ip 10.88.1.13\
  -v /etc/localtime:/etc/localtime:ro \
  -v /var/lib/tidb:/data \
  pingcap/tikv:latest \
  --addr="0.0.0.0:20160" \
  --advertise-addr="10.88.1.13:20160" \
  --data-dir="/data/tikv3" \
  --pd="10.88.1.1:2379"
```

### 部署 TIDB
```bash
podman run -d --name tidb \
  -p 4000:4000 \
  -p 10080:10080 \
  -v /etc/localtime:/etc/localtime:ro \
  pingcap/tidb:latest \
  --store=tikv \
  --path="10.88.1.1:2379"
```

### 登录
```bash
mysql -h 127.0.0.1 -P 4000 -u root -D test
> show databases;
```

## 修改密码
```bash
# 创建用户 CREATE USER 'test'@'localhost' IDENTIFIED BY 'mypass';
SET PASSWORD FOR 'root'@'%' = 'password';
FLUSH PRIVILEGES;
```