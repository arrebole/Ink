import { AbstractClass } from "./templateMethod"

class ConcreteClass extends AbstractClass {
    protected step2(){
        console.log("xxxxxxxxxxxx");
    }
}

let tm = new ConcreteClass();
tm.TemplateMethod();