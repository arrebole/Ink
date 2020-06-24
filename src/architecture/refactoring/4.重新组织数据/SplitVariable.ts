// 重构：拆分变量、分解临时变量

const height = 10;
const width = 20;

namespace BadSmell {
    let temp = 2 * (height + width)
    console.log(temp);
    temp = height * width;
    console.log(temp);
}
namespace GoodSmell { 
    const perimeter = 2 * (height + width);
    console.log(perimeter);
    const area = height * width;
    console.log(area)
}