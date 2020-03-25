class Singleton {
    private _data: string;

    data(): string {
        return this._data;
    }

    private constructor() {
        this._data = "hello world";
    }

    // 线程不安全的单例模式
    private static uniqueInstance: Singleton;
    static Instance(): Singleton {
        if (Singleton.uniqueInstance == null) {
            Singleton.uniqueInstance = new Singleton();
        }
        return this.uniqueInstance;
    }
};

function main(){
    console.log(Singleton.Instance().data())
}

