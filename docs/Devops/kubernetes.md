# kubernetes

容器编排技术



## Table of Contents

+ [简述]()
+ [特点]()
  + 崩溃恢复
  + 自动扩缩容
  + 滚动更新/版本回滚
+ k8s中的对象
  + [pod](#pod) 
  + [service](#service) 
  + [deployment](#deployment)
+ [部署一个k8s]()
  + [0.安装前准备](#0.安装前准备)
  + [1.安装docker](#1.安装docker)
  + [2.安装kubeadm、kubelet和kubectl](#2.安装kubeadm、kubelet和kubectl)
  + [3.安装kubernetes主节点](#3.安装kubernetes主节点)
  + [4.安装kubernetes从节点](#安装kubernetes从节点)
  + [5.配置集群网络](#5.配置集群网络)
  + [6.安装ingress](#6.安装ingress)
  + [7.部署Tomcat](#7.部署Tomcat)
  + [8.ingress暴露Tomecat](#8.ingress暴露Tomecat)
  + [9.通过ingress访问k8s集群中的tomcat](9.通过ingress访问k8s集群)



## 简述

K8S是2014年6月由Google公司正式公布出来并宣布开源的。K8S并不是一件全新的发明。它的前身，是Google自己捣鼓了十多年的**Borg系统**。kubernetes是舵手的意思，简称k8s来源于k与s之间有8个字符。

一个K8S系统，通常称为一个**K8S集群（Cluster）**。

这个集群主要包括两个部分：

- **Master节点（主节点）**
- **Node节点（计算节点）**



## 特点

####  崩溃恢复

程序运行时会出现各种不可抗拒因素，运行中的程序异常退出是很正常的事情，

k8s提供了崩溃恢复功能，异常退出的容器将会被自动重启。



#### 自动扩缩容

由于是在分布式系统中，当前的服务集群无法满足压力的时候，k8s提供弹性扩缩容功能。

系统压力增大时，自动增加瓶颈的服务实例，压力降低时，减小实例的数量，使得系统能够弹性的应对业务压力。



#### 滚动更新/版本回滚

新版本开发完成后，分批上线。如果出现意外，进行版本回滚。自动化运维，减少了大大降低了版本更新时出现异常时的损失。



## k8s中的对象

k8s中的对象分为 pod  deployment service

+ Pod是最小的调度单元，一个pod中可以包含多个相互关联的容器
+ deployment是pod的部署单元，用于管理pod，比如创建pod，删除pod。
+ service是通过apiserver创建出来的对象实例，是一组pod组成的服务，端口会暴露在k8s集群中。



## 部署一个k8s

> 我们所以程序尝试使用最新版本

### 0.安装前准备

#### 服务器配置

本次安装采用 ubuntu Server 19.10

- CPU：最低要求，1 CPU 2 核
- 内存：最低要求，4 GB
- 磁盘：最低要求，40 GB

| 主机名                | 角色   | 系统                | CPU/内存 | 磁盘 |
| --------------------- | ------ | ------------------- | -------- | ---- |
| kubernetes-master     | Master | Ubuntu Server 19.10 | 2 核 4G  | 40G  |
| kubernetes-cluster-01 | Node   | Ubuntu Server 19.10 | 2 核 4G  | 40G  |
| kubernetes-cluster-03 | Node   | Ubuntu Server 19.10 | 2 核 4G  | 40G  |

#### 关闭交换空间

```bash
# 关闭交换空间
swapoff -a
# 阻止开机后再次开启 如果有 swap 开头的行，进行注释
vi /etc/fstab
```

#### 配置主机名

```bash
# 修改主机名
hostnamectl set-hostname name # 改为主机的名字
```



### 1.安装docker

更新apt软件包索引并安装软件包以允许apt通过HTTPS使用存储库：

```bash
sudo apt-get update

sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common
```
添加Docker的官方GPG密钥
```bash
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
# OK
```
验证是否添加GPG成功
```bash
sudo apt-key fingerprint 0EBFCD88
# pub   rsa4096 2017-02-22 [SCEA]
#       9DC8 5822 9FC7 DD38 854A  E2D8 8D81 803C 0EBF CD88
# uid           [unknown] Docker Release (CE deb) <docker@docker.com>
# sub   rsa4096 2017-02-22 [S]
```

将源添加到apt

```bash
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
```

查看可安装的docker版本

```bash
sudo apt-cache madison docker-ce
# docker-ce | 5:19.03.8~3-0~ubuntu-eoan | https://download.docker.com/linux/ubuntu eoan/stable amd64 Packages
# docker-ce | 5:19.03.7~3-0~ubuntu-eoan | https://download.docker.com/linux/ubuntu eoan/stable amd64 Packages
# docker-ce | 5:19.03.6~3-0~ubuntu-eoan | https://download.docker.com/linux/ubuntu eoan/stable amd64 Packages
```

安装docker，**docker版本过高可能出现，超过k8s支持范围**

```bash
sudo apt-get install docker-ce docker-ce-cli containerd.io
```

查看已安装的docker版本

```bash
docker version
# Client: Docker Engine - Community
# Version:           19.03.8
# API version:       1.40
# Go version:        go1.12.17
# ...
```



### 2.安装kubeadm、kubelet和kubectl

> 主节点和从节点都需要安装

同样将源添加到apt仓库

```bash
sudo apt-get update && sudo apt-get install -y apt-transport-https curl

curl -s https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key add -
# OK

cat <<EOF | sudo tee /etc/apt/sources.list.d/kubernetes.list
deb https://apt.kubernetes.io/ kubernetes-xenial main
EOF
```
安装kubeadm、kubelet和kubectl
```bash
sudo apt-get update
sudo apt-get install -y kubelet kubeadm kubectl
```



### 3.安装kubernetes主节点

导出配置文件

```bash
kubeadm config print init-defaults --kubeconfig ClusterConfiguration > kubeadm.yml
```
修改配置文件

> vim ./kubeadm.yml

```yaml
apiVersion: kubeadm.k8s.io/v1beta2
bootstrapTokens:
- groups:
  - system:bootstrappers:kubeadm:default-node-token
  token: abcdef.0123456789abcdef
  ttl: 24h0m0s
  usages:
  - signing
  - authentication
kind: InitConfiguration
localAPIEndpoint:
  advertiseAddress: 1.2.3.4 # 改为本机ip地址
  bindPort: 6443
nodeRegistration:
  criSocket: /var/run/dockershim.sock
  name: vultr.guest
  taints:
  - effect: NoSchedule
    key: node-role.kubernetes.io/master
---
apiServer:
  timeoutForControlPlane: 4m0s
apiVersion: kubeadm.k8s.io/v1beta2
certificatesDir: /etc/kubernetes/pki
clusterName: kubernetes
controllerManager: {}
dns:
  type: CoreDNS
etcd:
  local:
    dataDir: /var/lib/etcd
imageRepository: k8s.gcr.io
kind: ClusterConfiguration
kubernetesVersion: v1.18.0 # 修改为当前k8s的版本号
networking:
  dnsDomain: cluster.local
  serviceSubnet: 10.96.0.0/12
scheduler: {}
```

查看所需镜像

```bash
kubeadm config images list --config kubeadm.yml
# k8s.gcr.io/kube-apiserver:v1.18.2
# k8s.gcr.io/kube-controller-manager:v1.18.2
# k8s.gcr.io/kube-scheduler:v1.18.2
# k8s.gcr.io/kube-proxy:v1.18.2
# k8s.gcr.io/pause:3.2
# k8s.gcr.io/etcd:3.4.3-0
# k8s.gcr.io/coredns:1.6.7
```

拉取镜像

```bash
kubeadm config images pull --config kubeadm.yml
# [config/images] Pulled k8s.gcr.io/kube-apiserver:v1.18.2
# [config/images] Pulled k8s.gcr.io/kube-controller-manager:v1.18.2
# [config/images] Pulled k8s.gcr.io/kube-scheduler:v1.18.2
# [config/images] Pulled k8s.gcr.io/kube-proxy:v1.18.2
# [config/images] Pulled k8s.gcr.io/pause:3.2
# [config/images] Pulled k8s.gcr.io/etcd:3.4.3-0
# [config/images] Pulled k8s.gcr.io/coredns:1.6.7
```

安装主节点

```bash
kubeadm init --config=kubeadm.yml --upload-certs | tee kubeadm-init.log

# kubeadm join 144.202.114.189:6443 --token m8omoq.6kel0kpywd43w56h \
#    --discovery-token-ca-cert-hash 
# sha256:43c268b45237457ec33977b77cd2e8bf6b6a7515567a8c3e4e199aceb3c7a41e
```

设置配置文件

```bash
mkdir -p $HOME/.kube
sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
sudo chown $(id -u):$(id -g) $HOME/.kube/config
```

验证节点是否安装成功

```bash
kubectl get node
# NAME          STATUS     ROLES    AGE     VERSION
# kubernetes-master   NotReady   master   4m18s   v1.18.2
```

如果失败进行重置

```bash
kubeadm reset
```



### 4.安装kubernetes从节点

从服务器加入到主节点

```bash
kubeadm join 144.202.114.189:6443 --token m8omoq.6kel0kpywd43w56h \
    --discovery-token-ca-cert-hash 
sha256:43c268b45237457ec33977b77cd2e8bf6b6a7515567a8c3e4e199aceb3c7a41e
```

主节点查看加入状况

```bash
kubectl get nodes
# NAME                    STATUS     ROLES    AGE     VERSION
# kubernetes-cluster-01   NotReady   <none>   7s      v1.18.2
# kubernetes-master       NotReady   master   2m14s   v1.18.2
```



### 5.配置集群网络

在master中安装CIN(Container Network Interface)插件, 我们使用`calico`

```bash
kubectl apply -f https://docs.projectcalico.org/manifests/calico.yaml
```

查看运行状况

```bash
kubectl get pods --all-namespaces
# 输出内容
NAMESPACE     NAME                                       READY   STATUS    RESTARTS   AGE
kube-system   calico-kube-controllers-6fcbbfb6fb-8nhrv   1/1     Running   0          65s
kube-system   calico-node-8ljdr                          1/1     Running   0          64s
kube-system   calico-node-tnb42                          1/1     Running   0          64s
kube-system   coredns-66bff467f8-c94tx                   1/1     Running   0          32m
kube-system   coredns-66bff467f8-jbx9n                   1/1     Running   0          32m
kube-system   etcd-vultr.guest                           1/1     Running   0          32m
kube-system   kube-apiserver-vultr.guest                 1/1     Running   0          32m
kube-system   kube-controller-manager-vultr.guest        1/1     Running   0          32m
kube-system   kube-proxy-nk4rj                           1/1     Running   0          32m
kube-system   kube-proxy-sp577                           1/1     Running   0          30m
kube-system   kube-scheduler-vultr.guest                 1/1     Running   0          32m
```

在从服务器查看docker的状态，calico也被推送到从服务器上了

```bash
docker images
# REPOSITORY                  TAG       IMAGE ID         CREATED         SIZE
# calico/node               v3.13.3     efc460414d9     3 days ago       261MB
# calico/pod2daemon-flexvol v3.13.3     d8e1bc26a77b    3 days ago       112MB
# calico/cni                v3.13.3     8229c7314d00    3 days ago          
```

在master节点查看网络状态, STATUS转化为了Ready。

```bash
kubectl get nodes
# NAME                    STATUS   ROLES    AGE   VERSION
# kubernetes-cluster-01   Ready    <none>   35m   v1.18.2
# kubernetes-maste        Ready    master   37m   v1.18.2
```



### 6.安装ingress

> 在k8s集群中只暴露单个入口

下载 Nginx Ingress Controller 配置文件

```bash
wget https://raw.githubusercontent.com/kubernetes/ingress-nginx/master/deploy/static/provider/cloud/deploy.yaml
```

修改配置文件

```
  vim deploy.yaml
 # 增加 hostNetwork: true，意思是开启主机网络模式，暴露 Nginx 服务端口 80
```

部署服务

```bash
kubectl apply -f deploy.yaml
```

查看状态

```bash
get pods -n ingress-nginx -o wide
```



### 7.部署 Tomcat

创建一个tomcat.yaml

```bash
touch tomcat.yaml
vim tomcat.yaml
```
修改tomact.yaml的内容

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: tomcat-app
spec:
  selector:
    matchLabels:
      # 容器标签的名字，发布 Service 时，selector 需要和这里对应
      app: tomcat
  replicas: 2
  template:
    metadata:
      labels:
        app: tomcat
    spec:
      containers:
      - name: tomcat
        image: tomcat:8.5.43
        imagePullPolicy: IfNotPresent
        ports:
        - containerPort: 8080
---
apiVersion: v1
kind: Service
metadata:
  name: tomcat-http
spec:
  ports:
    - port: 8080
      targetPort: 8080
  # ClusterIP, NodePort, LoadBalancer
  type: ClusterIP
  selector:
    app: tomcat
```

部署tomcat

```bash
kubectl apply -f tomcat.yaml
```

查看部署情况

```bash
kubectl get service
# NAME          TYPE        CLUSTER-IP     EXTERNAL-IP   PORT(S)    AGE
# kubernetes    ClusterIP   10.96.0.1      <none>        443/TCP    126m
# tomcat-http   ClusterIP   10.96.107.14   <none>        8080/TCP   76s
```



### 8.ingress暴露Tomecat

创建tomcat-ingress.yaml文件

```yaml
apiVersion: networking.k8s.io/v1beta1
kind: Ingress
metadata:
  name: nginx-web
  annotations:
    # 指定 Ingress Controller 的类型
    kubernetes.io/ingress.class: "nginx"
    # 指定我们的 rules 的 path 可以使用正则表达式
    nginx.ingress.kubernetes.io/use-regex: "true"
    # 连接超时时间，默认为 5s
    nginx.ingress.kubernetes.io/proxy-connect-timeout: "600"
    # 后端服务器回转数据超时时间，默认为 60s
    nginx.ingress.kubernetes.io/proxy-send-timeout: "600"
    # 后端服务器响应超时时间，默认为 60s
    nginx.ingress.kubernetes.io/proxy-read-timeout: "600"
    # 客户端上传文件，最大大小，默认为 20m
    nginx.ingress.kubernetes.io/proxy-body-size: "10m"
    # URL 重写
    nginx.ingress.kubernetes.io/rewrite-target: /
spec:
  # 路由规则
  rules:
  # 主机名，只能是域名，修改为你自己的
  - host: k8s.funtl.com
    http:
      paths:
      - path:
        backend:
          # 后台部署的 Service Name
          serviceName: tomcat-http
          # 后台部署的 Service Port
          servicePort: 8080
```

创建ingress

```bash
kubectl apply -f tomcat-ingress.yaml
```

查看ingress部署情况

```bash
kubectl get ingress
# nginx-web   <none>   k8s.funtl.com             80      43s
```



### 9.通过ingress访问k8s集群

修改本地host文件，将k8s.funtl.com指向服务器ip。

然后访问通过域名访问k8s.funtl.com，请求将会被代理到tomcat中。

