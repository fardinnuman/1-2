// SINGLE INHERITANCE

public class Java5_1 {
    class Shape {
        void area() {
            System.out.println("DISPLAYS AREA OF THE SHAPE");
        }
    }

    class Triangle extends Shape {
        int h = 4;
        int b = 5;

        void area() {
            System.out.println(0.5 * h * b);
        }
    }

    public static void main(String[] args) {

        Java5_1 obj = new Java5_1(); // OBJECT OF OUTER CLASS

        Shape s = obj.new Shape();
        s.area();

        Triangle t = obj.new Triangle();
        t.area();

    }
}