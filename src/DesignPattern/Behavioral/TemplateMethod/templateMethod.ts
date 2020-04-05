abstract class AbstractClass {
    TemplateMethod() {
       this.step1();
       this.step2();
       this.step3();
     }
   
    protected step1() { 
        console.log("step1 \n"); 
    }
    protected step3() { 
         console.log("step 3\n"); 
    }
    protected abstract step2();
};

class ConcreteClass extends AbstractClass {
    protected step2() { 
        console.log("xxxx\n");
    }
}
  
function main() {
    const t = new ConcreteClass();
    t.TemplateMethod();
}