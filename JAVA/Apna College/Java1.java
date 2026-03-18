public class Java1 {

    // CLASS CREATION
    class Student {
        String name;
        int age;

        void display() {
            System.out.println(name + " " + age);
        }
    }

    public static void main(String[] args) {

        Java1 ob = new Java1();

        Student s1 = ob.new Student(); // OBJECT CREATION

        s1.name = "Fardin";
        s1.age = 20;
        s1.display();

        Student s2 = ob.new Student(); // OBJECT CREATION

        s2.name = "Numan";
        s2.age = 20;
        s2.display();

    }
}
