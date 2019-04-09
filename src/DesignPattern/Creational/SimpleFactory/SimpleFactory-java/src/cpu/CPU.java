package cpu;

interface CPU {
    void printName();
}

class EmberCPU implements CPU {
    public void printName() {
        System.out.println("EmberCPU");
    }
}

class EnginolaCPU implements CPU {
    public void printName() {
        System.out.println("EnginolaCPU");
    }
}

enum CPUTypes {
    EmberCPU, EnginolaCPU,
};


class CPUFactory {
    private static final EmberCPU _EmberCPU = new EmberCPU();
    private static final EnginolaCPU _EnginolaCPU = new EnginolaCPU();

    public static CPU createFactory(CPUTypes t) {
        CPU cpu = null;
        switch (t) {
        case EmberCPU:
            cpu = _EmberCPU;
            break;
        case EnginolaCPU:
            cpu = _EnginolaCPU;
            break;
        }
        return cpu;
    }
}

class TestCPU{
    public static void main(String[] args) {
        CPUFactory.createFactory(CPUTypes.EmberCPU).printName();
        CPUFactory.createFactory(CPUTypes.EnginolaCPU).printName();
    }
}