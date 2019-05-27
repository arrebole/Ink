export interface State {
    use()
    next(): State
}

export class Context {
    private current: State
    public exec() {
        if (this.current == null) return;
        this.current.use();
        this.current = this.current.next();

    }
    public setState(state: State) {
        this.current = state;
    }
}

export class OpenState implements State{
    private static uniqueInstance: OpenState;
    public static Instance(){
        if(this.uniqueInstance == null){
            this.uniqueInstance = new OpenState();
        }
        return this.uniqueInstance;
    }
    public use(){
        console.log("Open ....")
    }

    public next():State{
        return SendState.Instance();
    }
}

export class SendState implements State{
    private static uniqueInstance: SendState;
    public static Instance(){
        if(this.uniqueInstance == null){
            this.uniqueInstance = new SendState();
        }
        return this.uniqueInstance;
    }
    public use(){
        console.log("send ...")
    }
    public next():State{
        return CloseState.Instance();
    }
}

export class CloseState implements State{
    private static uniqueInstance: CloseState;
    public static Instance(){
        if(this.uniqueInstance == null){
            this.uniqueInstance = new CloseState();
        }
        return this.uniqueInstance;
    }
    public use(){
        console.log("close ...")
    }
    public next():State{
        return null;
    }

}