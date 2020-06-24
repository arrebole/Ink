interface Cat{
    miaomiao(): string
}

interface Dog{
    wangwang(): string
}

class Tomcat implements Cat{
    miaomiao(){
        return "miao miao miao!"
    }
}

// 将猫适配成狗
class Asaptee implements Dog{
    private cat: Cat
    constructor(cat: Cat){
        this.cat = cat;
    }
    wangwang(){
        return this.cat.miaomiao()
    }
}

function main(){
    const dog = new Asaptee(new Tomcat());
    console.log(dog.wangwang())
}