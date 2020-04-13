class Memento {
    private state: number;

    getState(): number {
        return this.state;
    }
    setState(state: number) {
        this.state = state;
        return this
    }
};

class Originator {
    private state: number;

    public setMemento(m: Memento) {
        this.state = m.getState();
    }
    CreateMemento(): Memento {
        return new Memento().setState(this.state);
    }
};

function main(){
    const originator = new Originator();
    const m = originator.CreateMemento();
    originator.setMemento(m);
}