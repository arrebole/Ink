interface State {
    use();
    next(): State;
};

class Context {
    private current: State;

    setCurrent(s: State) {
        this.current = s;
    }
    exec() {
        if (this.current == null) return;
        this.current.use();
        this.current = this.current.next();
    };
};

class CloseState implements State {
    private constructor() { }

    use() {
        console.log("close ....\n");
    }
    next() {
        return null;
    }

    private static uniqueInstance: State;
    static Instance(): State {
        if (this.uniqueInstance == null) {
            this.uniqueInstance = new CloseState();
        }
        return this.uniqueInstance;
    }
};

class SendState implements State {
    private constructor() { }
    use() {
        console.log("send ...\n");
    }
    next(): State {
        return CloseState.Instance();
    }

    private static uniqueInstance: State;
    static Instance(): SendState {
        if (this.uniqueInstance == null) {
            this.uniqueInstance = new SendState();
        }
        return this.uniqueInstance;
    }
};

class OpenState implements State {
    private constructor() { }

    use() {
        console.log("open ...\n");
    }
    next(): State {
        return SendState.Instance();
    }

    private static uniqueInstance: State;
    static Instance(): SendState {
        if (this.uniqueInstance == null) {
            this.uniqueInstance = new OpenState();
        }
        return this.uniqueInstance;
    }
};

function main(){
    const context = new Context();
    context.setCurrent(OpenState.Instance());
    context.exec();
    context.exec();
    context.exec();
}