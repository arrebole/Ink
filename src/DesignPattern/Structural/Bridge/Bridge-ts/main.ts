import { NewBridgeLinux,NewBridgeWin } from "./bridge";


let linux = NewBridgeLinux();
let win = NewBridgeWin();

console.log(linux.getPro());
console.log(win.getPro());