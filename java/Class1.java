public class Class1 {

    // CLASS CREATION
    static class Student {
        String name;
        int age;

        void display() {
            System.out.println(name + " " + age);
        }
    }

    public static void main(String[] args) {

        Student s1 = new Student(); // OBJECT CREATION

        s1.name = "Fardin";
        s1.age = 20;
        s1.display();

        Student s2 = new Student(); // OBJECT CREATION

        s2.name = "Numan";
        s2.age = 20;
        s2.display();

    }
}
