public class Java0 {

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

    public static void main(String args[]) {

        Java0 ob = new Java0();

        ob.display();

        ob.sum(5, 3);

    }
}
