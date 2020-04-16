interface ComputerPart {
    accept(visitor: ComputerPartVisitor): void;
}

interface ComputerPartVisitor {
    visitorKeyboard(part: ComputerPart): void;
    visitorMouse(part: ComputerPart): void;
}

class Keyboard implements ComputerPart {
    accept(visitor: ComputerPartVisitor) {
        visitor.visitorKeyboard(this)
    }
}

class Mouse implements ComputerPart {
    accept(visitor: ComputerPartVisitor) {
        visitor.visitorMouse(this)
    }
}

// `ObjectStructure` 能枚举它的元素，能提供一个高层接口以允许该访问者访问它的元素
class MacBook implements ComputerPart {
    private parts: ComputerPart[]
    constructor() {
        this.parts = new Array<ComputerPart>();
    }
    add(part: ComputerPart) {
        this.parts.push(part);
    }
    accept(visitor: ComputerPartVisitor) {
        for (const iterator of this.parts) {
            iterator.accept(visitor);
        }
    }
}

class ComputerPartDisplayVisitor implements ComputerPartVisitor {
    visitorKeyboard(part: ComputerPart) {
        console.log("displaying Keyboard")
    }
    visitorMouse(part: ComputerPart) {
        console.log("displaying Mouse")
    }
}

function main() {
    const macbook = new MacBook();
    macbook.add(new Keyboard())
    macbook.add(new Mouse())
    macbook.accept(new ComputerPartDisplayVisitor());
}