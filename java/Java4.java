// POLYMORPHISM
//    2. Run Time Polymorphism -> Function Overriding

public class Java4 {

    class Shape {
        void area() {
            System.out.println("DISPLAYS AREA OF THE SHAPE");
        }
    }

    class Triangle extends Shape {
        @Override
        void area() {
            System.out.println("DISPLAYS AREA OF THE TRIANGLE");
        }
    }

    class Circle extends Shape {
        @Override
        void area() {
            System.out.println("DISPLAYS AREA OF THE CIRCLE");
        }
    }

    public static void main(String[] args) {

        Java4 ob = new Java4(); // OBJECT OF OUTER CLASS

        Shape s1 = ob.new Shape();
        s1.area();

        Triangle t1 = ob.new Triangle();
        t1.area();

        Circle c1 = ob.new Circle();
        c1.area();

    }

}
