interface Sort {
    solve(arr: number[]): number[];
};

class BubbleSort implements Sort {
    solve(arr: number[]) {
        //....
        return arr;
    }
};

class MergerSort implements Sort {
    solve(arr: number[]) {
        //.....
        return arr
    }
};

class Context {
    private strategy: Sort;
    constructor(strategy: Sort) {
        this.strategy = strategy
    }
    exec(arr: number[]) {
        return this.strategy.solve(arr);
    }
};

function sample() {
    const c1 = new Context(new BubbleSort());
    const c2 = new Context(new MergerSort());
    c1.exec([2, 1, 3]);
    c2.exec([2, 3, 2]);
}
