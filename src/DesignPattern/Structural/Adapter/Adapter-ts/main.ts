import { ITarget, IAdaptee, Adapter, Adaptee } from "./adapter";


let adapter: IAdaptee = new Adaptee();
let target: ITarget = new Adapter(adapter);


console.log(target.getYear());