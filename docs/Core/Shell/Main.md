# Shell命令

## GUN

### 编译器命令 

>-c



#### 编译静态链接库

```shell
gcc -c a.c -o a.o
ar -cr x.a x.o
```



#### 编译动态链接库

```shell
gcc -fPIC -shared -o a.so a.c
```



#### 链接

```shell
# 动态链接（1）
gcc main.c ./name.so

# 动态链接（2）
# -L+链接的文件目录 -l:链接库名称 -rpath+运行时加载链接库的路径
gcc main.c -L . -l:name.so -rpath=.
```

```shell
# 静态链接(1)
gcc main.c ./name.lib

# 静态链接(2)
# 默认 .lib 结尾
gcc main.c -L. -lname
```

