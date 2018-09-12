
function setStyle(el) {
    let drawing = document.getElementById(el);
    drawing.style.height = "500px";
    drawing.style.width = "100%";
}

function drawRect(el) {
    let drawing = document.getElementById(el);
    let context = drawing.getContext("2d");

    // 绘制矩形
    context.fillStyle = "#ff0000";
    context.fillRect(10, 10, 50, 50);
    context.strokeStyle = "rgba(0,0,255,0,0.5)";
    context.strokeRect(10, 10, 50, 50);
}

function drawClock(el) {
    let drawing = document.getElementById(el);
    let context = drawing.getContext("2d");
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


}


function main() {
    setStyle("drawing");
    drawRect("drawing")
    drawClock("drawing")

}

main()