export default class Singleton {
    private constructor() { }

    public doSomething(){
        console.log("do some ...");
    }

    private static uniqueInstance= null;

    public static Instance(): Singleton {
        if (this.uniqueInstance == null) {
            this.uniqueInstance = new Singleton();
        }
        return this.uniqueInstance;
    }
}