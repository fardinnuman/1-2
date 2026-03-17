public class A {

    // NORMAL METHOD
    void display() {
        System.out.println("THIS IS A NORMAL METHOD");
    }

    // SUM METHOD
    int sum(int a, int b) {
        System.out.println("THIS IS A SUM METHOD");
        System.out.println(a + b);
        return a + b;
    }

    // SUB METHOD
    int sub(int a, int b) {
        System.out.println("THIS IS A SUB METHOD");
        System.out.println(a - b);
        return a - b;
    }

    // MUL METHOD
    int mul(int a, int b) {
        System.out.println("THIS IS A MUL METHOD");
        System.out.println(a * b);
        return a * b;
    }

    // DIV METHOD
    int div(int a, int b) {
        System.out.println("THIS IS A DIV METHOD");
        System.out.println(a / b);
        return a / b;
    }

    // MOD METHOD
    int mod(int a, int b) {
        System.out.println("THIS IS A MOD METHOD");
        System.out.println(a % b);
        return a % b;
    }

    public static void main(String args[]) {

        A a = new A();

        a.display();

        a.sum(5, 3);
        a.sub(5, 3);
        a.mul(5, 3);
        a.div(5, 3);
        a.mod(5, 3);

    }
}
