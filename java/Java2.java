// CONSTRUCTORS

public class Java2 {

    static class Student {

        String name;
        int age;

        // NON-PARAMETERIZED CONSTRUCTOR
        Student() {
            System.out.println("THIS IS A NON-PARAMETERIZED CONSTRUCTOR");
        }

        // PARAMETERIZED CONSTRUCTOR
        Student(String name, int age) {
            System.out.println("THIS IS A PARAMETERIZED CONSTRUCTOR");

            this.name = name;
            this.age = age;
            System.out.println(name + " " + age);
        }

        // COPY CONSTRUCTOR
        Student(Student student2) {
            System.out.println("THIS IS A COPY CONSTRUCTOR");

            this.name = student2.name;
            this.age = student2.age;
            System.out.println(name + " " + age);
        }

    }

    public static void main(String[] args) {

        Student student1 = new Student(); // CALLING NON-PARAMETERIZED CONSTRUCTOR
        Student student2 = new Student("Numan", 20); // CALLING PARAMETERIZED CONSTRUCTOR
        Student student3 = new Student(student2); // CALLING COPY CONSTRUCTOR

    }

}
