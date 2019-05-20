interface IFont {
    getValue(): string;
}

class Font implements IFont {
    private value: string;
    constructor(val: string) {
        this.value = val
    }
    public getValue(): string {
        return this.value;
    }
}

export class FontFactory {
    private pool: Map<number, IFont>;
    constructor() {
        this.pool = new Map<number, IFont>();
    }
    public GetFont(key: number): IFont {
        if (!this.pool.has(key)) {
            let item = new Font(`!${key}`);
            this.pool.set(key, item)
            return item;
        }
        return this.pool.get(key);
    }
}