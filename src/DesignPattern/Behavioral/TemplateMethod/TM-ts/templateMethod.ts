export abstract class AbstractClass {
    public TemplateMethod() {
        this.step1();
        this.step2();
        this.step3();
    }
    protected step1() {
        console.log("step 1");
    }
    protected abstract step2();

    protected step3() {
        console.log("step 3");
    }

}

