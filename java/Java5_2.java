// HIERARCHICAL INHERITANCE

public class Java5_2 {

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

    class Circle extends Shape {
        int r = 5;

        void area() {
            System.out.println(3.14 * r * r);
        }
    }

    public static void main(String[] args) {

        Java5_2 obj = new Java5_2(); // OBJECT OF OUTER CLASS

        Shape s = obj.new Shape();
        s.area();

        Triangle t = obj.new Triangle();
        t.area();

        Circle c = obj.new Circle();
        c.area();
    }
}
