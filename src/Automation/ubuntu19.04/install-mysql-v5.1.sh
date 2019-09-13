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

// 修改权限 (注意这里用户名和密码替换成自己的)
 GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY 'PASSWORD' WITH GRANT OPTION;
 //更新缓存
 FLUSH PRIVILEGES;

# 设置本机访问需要密码
#select user,Host, plugin from mysql.user;
#update mysql.user set plugin = 'mysql_native_password' where user = 'root' and host='localhost';

# 修改配置
#vi /etc/mysql/mysql.conf.d/mysqld.cnf

#找到如下这一行，注释掉
#bind-address = 127.0.0.1 //即前面加上#

# 重启
#service mysql restart

# 修改字符集
#ALTER DATABASE 数据库名 CHARACTER SET 'utf8mb4' COLLATE 'utf8mb4_general_ci';

# 修改root密码
#bin/mysqladmin -u root password 'password'
#进入数据库
#bin/mysql -u root -p
#展示数据库
# show databases;