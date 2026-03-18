// CONSTRUCTORS

public class Java2 {

    class Student {

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

        Java2 ob = new Java2();

        Student student1 = ob.new Student(); // CALLING NON-PARAMETERIZED CONSTRUCTOR
        Student student2 = ob.new Student("Numan", 20); // CALLING PARAMETERIZED CONSTRUCTOR
        Student student3 = ob.new Student(student2); // CALLING COPY CONSTRUCTOR

    }

}
