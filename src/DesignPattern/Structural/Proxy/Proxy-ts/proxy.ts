
interface Subject{
    TouchFile(fileName: string)
}

class FileProxy implements Subject{
    public TouchFile(fileName:string){
        console.log(".....")
        let f = new RealSubject();
        f.TouchFile(fileName);
        console.log("完成")
    }
}

class RealSubject implements Subject{
    public TouchFile(fileName:string){
        //.....
    }
}