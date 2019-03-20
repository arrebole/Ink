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
# -L+路径 -l:名称
gcc main.c -L. -l:name.so


# 静态链接(1)
gcc main.c ./name.lib
# 静态链接(2)
# 默认 .lib 结尾
gcc main.c -L. -lname
```

