abstract class Component {
    protected data: number;
    abstract Print();
    abstract Increase();
    abstract Add(compl: Component);
}

class Composite extends Component {
    private Components: Array<Component>;
    constructor(n: number) {
        super()
        this.data = n;
        this.Components = new Array<Component>();
    }
    public Add(compl: Component) {
        this.Components.push(compl);
    }
    public Print() {
        console.log("Composite %d", this.data);
        for (const iterator of this.Components) {
            iterator.Print();
        }
    }
    public Increase() {
        this.data++;
        for (const iterator of this.Components) {
            iterator.Increase();
        }
    }
}

class Leaf extends Component {
    constructor(n: number) {
        super()
        this.data = n;
    }
    public Add(compl: Component) {
        throw "叶子类无法添加子类";
    }
    public Increase() {
        this.data++;
    }
    public Print() {
        console.log("Leaf %d", this.data);
    }
}

function main() {
    const root = new Composite(0);
    root.Add(new Leaf(1))
    root.Add(new Leaf(2))
    let compl = () => {
        let p = new Composite(12);
        p.Add(new Leaf(19));
        p.Add(new Leaf(67));
        return p;
    }
    root.Add(compl());

    root.Print();
    root.Increase();
    root.Print();
}