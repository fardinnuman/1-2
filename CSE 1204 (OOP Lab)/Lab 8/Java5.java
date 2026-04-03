interface AI {
    void PrintA();
}

interface BI {
    void PrintB();
}

interface CI {
    void PrintC();
}

// Class A implements AI
class A implements AI {
    public void PrintA() {
        System.out.println("This is PrintA from Interface AI");
    }
}

// Class B extends A and implements BI
class B extends A implements BI {
    public void PrintB() {
        System.out.println("This is PrintB from Interface BI");
    }
}

// Class C extends B and implements CI
class C extends B implements CI {
    public void PrintC() {
        System.out.println("This is PrintC from Interface CI");
    }
}

public class Java5 {
    public static void main(String[] args) {

        C obj = new C();

        obj.PrintA();
        obj.PrintB();
        obj.PrintC();
    }
}

