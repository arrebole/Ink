export interface Strategy {
    Print(data: string)
}

export class BinaryPrint implements Strategy {
    public Print(data: string) {
        const BinaryArray: number[] = new Array<number>();
        for (let i = 0; i < data.length; i++) {
            BinaryArray.push(data.charCodeAt(i));
        }
        console.log(BinaryArray);
    }
}

export class TypeWriter {
    public out(strategy: Strategy, data: string) {
        strategy.Print(data);
    }
}