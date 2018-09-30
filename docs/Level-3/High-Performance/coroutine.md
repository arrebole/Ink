## Coroutine/异步

协程是轻量级的线程，主要应用在io密集型非阻塞操作。其主要实例为异步非阻塞模型，利用单线程模拟并发。

异步的实质是在单线程中控制函数的调度，将需要等待的函数挂起，继续执行后面的函数，在事件驱动下再回头执行挂起的函数。

#### python中的实现

pthon中的协程异步是通过 yield（构造器）实现。yield 有类似return的功能，能在函数中实现中断挂起。

```python
def say():
    yield "hello"
    yield "world"

c = say()           #返回构造器函数
print(next(say))	#执行到 返回hello 处被挂起，通过next可以继续被挂起的任务
print(next(say))	# 继续返回 world
```



python 3.5+ 对异步操作进行了封装，通过async/await 和asyncio包 能够容易实现,在src中有详细代码

+ async 修饰的是异步函数
+ await 后面的是异步函数 



```python
async def print_num(n):
    await asyncio.sleep(2) # 睡两秒 模拟io
    print(n)
```

单协程实现

```python
# 获取事件驱动
loop = asyncio.get_event_loop()
# 调用协程
loop.run_until_complete(print_num(5))
```



多个协程

```python
#1、创建协程
loop = asyncio.get_event_loop()
#2、安排任务
coroutine_list = [print_num(num) for num in rang(10)]
corountine = asyncio.wait(corountine_list)
#3、执行任务
loop.run-until_complete(coroutine)
#4、关闭
loop.close()
```



####  javaScript中的实现

在es5之前javascript没有异步，函数的调度是通过回调函数来实现的，当时称为回调噩梦；

```javascript
function fn1(){
    console.log("hello");
}
// 将函数变成参数传入，当函数执行完，再执行参数函数（称回调函数）
function fn2(fun){
    console.log("world");
    fun()
}

// 执行
//在fn2之后执行fn1
fn2(fn1)

```

es5之后出现了promise对象

```javascript
var fn1 = function(){
    return new Promise((resolve,reject)=>{
        //...
        if !err{
          reject(err)  // 失败。将会调用 catch方法
        }
        resolve(res) // 成功。将会调用then方法
    })
}

fn1.then((res)=>{
    console.log(res);
}).catch((err)=>{
    console.log(err)
})
```

es7出现async/await，是promise的语法糖，await后面跟着promise函数

```javascript
function fn1(){
    return Promise((resolve,reject)=>{
        resolve(res)
    })
}

async function fn(){
    res = await fn1();
}
```

