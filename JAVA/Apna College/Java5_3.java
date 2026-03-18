// MULTI-LEVEL INHERITANCE

public class Java5_3 {

    class Shape {
        void area() {
            System.out.println("DISPLAYS AREA OF THE SHAPE");
        }
    }

    class Rectangle extends Shape {
        int l = 5;
        int w = 3;

        void area() {
            System.out.println(l * w);
        }
    }

    class Square extends Rectangle {
        int s = 4;

        void area() {
            System.out.println(s * s);
        }
    }

    public static void main(String[] args) {

        Java5_3 obj = new Java5_3(); // // OBJECT OF OUTER CLASS

        Shape s = obj.new Shape();
        s.area();

        Rectangle r = obj.new Rectangle();
        r.area();

        Square sq = obj.new Square();
        sq.area();
    }
}