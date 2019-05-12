import { ConcretePrototype,PrototypeManager } from "./prototype";

let manager = new PrototypeManager();

let product1 = new ConcretePrototype();
manager.register("a",product1);
let product2 = manager.retrieve("a").clone();

console.log(product1.getDate());
console.log(product2.getDate());
console.assert(product1 === product2);