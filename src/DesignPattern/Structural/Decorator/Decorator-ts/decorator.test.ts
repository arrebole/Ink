import { Core, Wrapper, Component } from "./decorator";


let core: Component = new Core();
let wrapper: Component = new Wrapper(new Wrapper(core));

let count: number = wrapper.Count();
console.assert(count == 200, "error");