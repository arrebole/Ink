apt-get update
# 安装包以允许apt通过HTTPS使用存储库：
apt-get install apt-transport-https ca-certificates curl gnupg-agent software-properties-common
# 添加Docker的官方GPG密钥
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
apt-key fingerprint 0EBFCD88
# 设置稳定存储库,夜间或测试存储库
add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
# 安装最新版本的Docker Engine
apt-get update && apt-get install docker-ce docker-ce-cli containerd.io

# 安装指定版本
# apt-get install docker-ce=5:18.09.9~3-0~ubuntu-bionic docker-ce-cli=5:18.09.9~3-0~ubuntu-bionic containerd.io
# or export VERSION=18.03 && curl -sSL get.docker.com | sh