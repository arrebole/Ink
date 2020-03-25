interface Image {
    getData(): number;
    Clone(): Image;
};

// 具体的原型类
class ConcreteImage implements Image {
    private data: number

    constructor(data: number) {
        this.data = data;
    }

    Clone() {
        return new ConcreteImage(this.data);
    }

    getData(): number {
        return this.data;
    }
};

function main() {
    const img = new ConcreteImage(17);
    const imgClone = img.Clone();

    console.log(img.getData());
    console.log(imgClone.getData());
}