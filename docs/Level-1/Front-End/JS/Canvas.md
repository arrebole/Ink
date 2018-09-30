## Canvas

#### 基本用法

+ 创建 canvas 元素
+ 对浏览器进行canvas检测
+ 绘制内容

```html
<canvas id = "drawing"></canvas>

<script>
	var drawing = document.getElementById("drawing");
    // 支持检测
    if (drawing.getContext){
    	var context = drawing.getContext("2s");
        //...
    }

</script>
```



#### 1、绘制矩形

api

+ getContext() 

+ fillStyle 填充样式
+ fillRect() 绘制矩形
+ strokeStyle 描边样式
+ stokeRect() 绘制矩形边框
+ clearRect() 镂空矩形

```javascript
// 获取元素
var drawing = document.getElementById("drawing");
// 获取canvas内容
var context = drawing.getContext("2d");
// 绘制矩形
context.fillRect(30,30,50,50);
// 填充颜色
context.fillStyle = "rgba(0,0,255,0.5)";
// 描边
context.strokeStyle = "rgba(0,0,255,0,0.5)";
context.stokeRect(30，30，50，50)；
```



#### 2、绘制路径

+ 创建路径起始点

+ 调用绘制方法去绘制出路径

+ 把路径封闭

+ 一旦路径生成，通过描边或填充路径区域来渲染图形

api

+ arc(x, y, r, startAngle, endAngle, anticlockwise):
+ beginPath() 
+ moveTo(x, y)
+ closePath()
+ stroke()
+ fill()

```javascript
    // 开始路径
    context.beginPath();
    // 绘制外圈
    context.arc(100, 100, 50, 0, 2 * Math.PI, false)
    // 绘制内圈
    context.moveTo(145, 100)
    context.arc(100, 100, 45, 0, 2 * Math.PI, false)
    // 绘制分针
    context.moveTo(100, 100)
    context.lineTo(100, 55)
    // 绘制时钟
    context.moveTo(100, 100)
    context.lineTo(75, 100);
    //描边路径
    context.stroke()
```

