
interface Iterators {
    hasNext(): boolean;
    next(): Iterators;
    value(): any
}

interface Container {
    iterator(): Iterators;
    size(): number;
    get(i: number): string
}

class NameRepository implements Container {
    protected name = ["a", "b", "c"];
    get(i: number): string {
        if (i > this.size() - 1) {
            throw Error("overflow")
        }
        return this.name[i];
    }
    size(): number {
        return this.name.length;
    }
    iterator(): Iterators {
        return new NameIterators(this);
    }
}

class NameIterators implements Iterators {
    private repos: Container
    private currIndex: number
    constructor(repos: Container) {
        this.repos = repos;
        this.currIndex = 0;
    }
    hasNext(): boolean {
        if (this.currIndex + 1 > this.repos.size()) return false;
        return true;
    }
    next(): Iterators {
        if (this.hasNext()) this.currIndex++;
        return this;
    }
    value() {
        return this.repos.get(this.currIndex);
    }
}


function main() {
    const repo = new NameRepository();
    for (let itor = repo.iterator(); itor.hasNext(); itor.next()) {
        console.log(itor.value())
    }
}