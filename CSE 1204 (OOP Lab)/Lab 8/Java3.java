public class Java3 {

    static class A {
        private int a = 10; // private member of A

        class B {
            private int b = 20; // private member of B

            void sum() {
                System.out.println("Sum: " + (a + b));
            }
        }
    }

    public static void main(String[] args) {

        A a = new A();
        A.B b = a.new B();
        b.sum();

    }
}

