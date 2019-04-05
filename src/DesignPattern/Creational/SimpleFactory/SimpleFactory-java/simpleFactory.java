
interface product {
    void getColor();
}

class productA implements product {
    public void getColor() {
        System.out.println("red");
    }
}

class productB implements product {
    public void getColor() {
        System.out.println("blank");
    }
}



public class simpleFactory {
    enum types {
        A, B,
    };

    public static product createFactory(types t) {
        switch (t) {
        case A:
            return new productA();
        case B:
            return new productB();
        }
        return null;
    }
}