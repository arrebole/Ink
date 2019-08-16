wget https://downloads.mysql.com/archives/get/file/mysql-5.1.73-linux-x86_64-glibc23.tar.gz
tar -zxvf mysql-5.1.73-linux-x86_64-glibc23.tar.gz

# 移动安装文件
sudo mv mysql-5.1.73-linux-x86_64-glibc23 /usr/local/mysql-5.1
cd /usr/local/mysql-5.1/


# 创建用户和组
sudo groupadd mysql
sudo useradd -g mysql mysql

#修改目录拥有者
sudo chown -R mysql .
sudo chgrp -R mysql .

# 初始化数据库
sudo scripts/mysql_install_db --user=mysql --basedir=/usr/local/mysql-5.1 --datadir=/usr/local/mysql-5.1/data/

#启动 
bin/mysqld_safe &

# 修改root密码
#bin/mysqladmin -u root password 'password'
#进入数据库
#bin/mysql -u root -p
#展示数据库
# show databases;