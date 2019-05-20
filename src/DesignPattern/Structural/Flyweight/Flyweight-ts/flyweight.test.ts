import { FontFactory } from "./flyweight";

let f = new FontFactory();
let item1 = f.GetFont(10);
let item2 = f.GetFont(10);
let item3 = f.GetFont(11);

console.log(item1.getValue(),item2.getValue(),item3.getValue());
console.log(item1 == item2);