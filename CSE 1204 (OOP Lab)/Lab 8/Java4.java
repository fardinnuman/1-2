class A {
    int x;

    A() {
        x = 10;
    }

    A(int x) {
        this.x = x;
    }

    int getX() {
        return x;
    }
}

class B extends A {
    int y;

    B() {
        super(100);
        y = 20;
    }

    void display() {
        System.out.println("x from class A: " + super.x);
        System.out.println("getX() from class A: " + super.getX());
    }
}

public class Java4 {
    public static void main(String[] args) {
        B b = new B();
        b.display();
    }
}

