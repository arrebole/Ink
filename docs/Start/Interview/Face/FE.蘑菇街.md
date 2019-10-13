
2、自我介绍

## 3、如何实现一个倒计时功能，类似于蘑菇街中的秒杀。
> ideas: 同步问题

+ setTimeout递归，并且内部做误差矫正
+ 因为setTimeout走的是even loop中的宏任务队列,不能保证精度。

4、怎么理解es6箭头函数中的this，它和一般函数的this指向有什么区别呢？
> ideas: es6-箭头函数, es-this作用域

+ 箭头函数不会创建自己的this,this是绑定的,它会从自己的作用域链的上一层继承this
+ 对象成员函数的this指向该函数被调用的环境，构造函数的this指向该对象实例。
+ 在严格模式下，全局作用域中普通函数中的this=undefined，非严格下指向全局对象


## 5、一个矩形，里面一个樱桃，过樱桃做一条直线， 并且没有数据和测量工具，如果做到平分矩形呢？
> ideas：利用数学知识

+ 这条直线必过矩形中心
连接矩形中心和樱桃

6、说一下同源策略
> idea: 网络-跨域

+ 同源指：同协议、同主机、同端口
+ 目的：网络安全

7、vue中的路由时如何管理的？ 你知道他的实现方式吗？
> ideas: 前端框架，vue vue-router

+ 通过vue-router实现，前端路由
+ 内部维护路由栈
+ Hash模式：使用URL的hash来模拟一个完整的URL，锚点
+ History模式：浏览器支持的history api, history.pushState 和 history.replaceState。

8、提到了我的博客，问我的博客相关问题。