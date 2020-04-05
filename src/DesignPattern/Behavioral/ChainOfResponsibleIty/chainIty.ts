// 1、创建抽象的记录器类。
abstract class AbstractLogger {
    protected level: number = 0;

    //责任链中的下一个元素
    protected nextLogger: AbstractLogger | null = null;

    public setNextLogger(nextLogger: AbstractLogger): void {
        this.nextLogger = nextLogger;
    }
    public logMessage(level: number, message: string): void {
        if (this.level == level) this.write(message);
        if (this.nextLogger != null) {
            this.nextLogger.logMessage(level, message);
        }
    }
    protected abstract write(message: string): void;
}

class WarnLogger extends AbstractLogger {
    constructor(level: number) {
        super()
        this.level = level
    }
    protected write(message: string) {
        console.log("[warn]: %s", message);
    }
}

class DangerLogger extends AbstractLogger {
    constructor(level: number) {
        super()
        this.level = level
    }
    protected write(message: string) {
        console.log("[Danger]: %s", message);
    }
}

function main() {
    const logger = new WarnLogger(1);
    const dangerLogger = new DangerLogger(2);

    logger.setNextLogger(dangerLogger);

    logger.logMessage(1, "hello world");
    logger.logMessage(2, "hello world");
}