interface Mediator {
    use1();
    use2();
    setC1(Colleague): Colleague;
    setC2(Colleague): Colleague;
};

abstract class Colleague {
    protected mediator: Mediator
    abstract use()
};

class ConcreteColleague1 extends Colleague {
    constructor(mediator: Mediator) {
        super()
        this.mediator = mediator;
    }

    use() {
        console.log("use Colleague 1");
        this.mediator.use2();
    }
};

class ConcreteColleague2 extends Colleague {
    constructor(mediator: Mediator) {
        super()
        this.mediator = mediator;
    }
    use() {
        console.log("use Colleague 2\n");
    }
};

class ConcreteMediator implements Mediator {
    private c1: Colleague;
    private c2: Colleague;


    setC1(c1: Colleague) {
        this.c1 = c1;
        return c1;
    }
    setC2(c2: Colleague) {
        this.c2 = c2;
        return c2
    }

    use1() { this.c1.use() }
    use2() { this.c2.use() }
};

function main() {
    const m = new ConcreteMediator();
    const c1 = m.setC1(new ConcreteColleague1(m));
    const c2 = m.setC2(new ConcreteColleague2(m));
    c1.use();
}