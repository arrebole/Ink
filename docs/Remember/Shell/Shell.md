# BashShell


## Compiler

#### 编译静态链接库

```shell
gcc -c a.c -o a.o
ar -cr x.a x.o
```

#### 编译动态链接库

gcc -fPIC -shared -o a.so a.c

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
gcc main.c -L . -lname
```



## Process

### fork

> fork 创建一个新的进程，fork会创建原有进程的贮存的精确拷贝。
>
> 子shell执行的时候, 父shell还在。子shell执行完毕后返回父shell。子shell从父shell继承环境变量.但是子shell中的环境变量不会带回父 shell

```shell
fork 
```



### source 

> 与fork的区别是不新开一个子shell进程来执行被调用的脚本，而是在同一个shell中执行。所以被调用的脚本中声明的变量和环境变量, 都可以在主脚本中得到和使用。

```shell
source ~/.bashrc
```



### exec

>替换进程。 exec 被调用的脚本与父脚本在同一个shell内执行。但是使用exec调用一个新脚本以后, 父脚本中exec行之后的内容就不会再执行了，即不会返回到原来的shell

### (语句;语句)

> 启动子SHELL

### {语句；语句}

>不会启动子SHELL





# PowerShell

## Get-Alias

### 获取别名

```powershell
gal 
```

