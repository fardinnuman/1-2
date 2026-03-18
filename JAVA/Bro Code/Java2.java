public class Java2 {

    class Student {
        String name;
        int age;
        double cgpa;
        boolean isEnrolled;

        // CONSTRUCTOR
        Student(String name, int age, double cgpa) {
            this.name = name;
            this.age = age;
            this.cgpa = cgpa;
            this.isEnrolled = true; // NOT NECESSARILY NEEDS TO BE PASSED AS PARAMETERS, CAN BE SEPERATELY ASSIGNED
                                    // TOO
        }
        // this -> REFERS TO THE OBJECT WE ARE CURRENTLY WORKING WITH

        // WHEN WE CREATE student1, this = student1
        // SO IT BECOMES, student1.name = name; student1.age = age; student1.cgpa =
        // cgpa;
        // WHEN WE CREATE student2, this = student2
        // SO IT BECOMES, student2.name = name; student2.age = age; student2.cgpa =
        // cgpa;

        void study() {
            System.out.println(this.name + " is studying");
        }

    }

    // public class Student {
    // String name;
    // int age;
    // double cgpa;
    // boolean isEnrolled;

    // BTW, PARAMETERS' NAME DOESN'T NECESSARILY NEED TO BE SAME AS THE ATTRIBUTES'
    // NAME. THO, KEEPING SAME IS BETTER
    // Student(String x, int y, double z) {
    // this.name = x;
    // this.age = y;
    // this.cgpa = z;
    // }

    // }

    public static void main(String[] args) {

        Java2 ob = new Java2();

        Student student1 = ob.new Student("Numan", 20, 3.39);
        Student student2 = ob.new Student("Fardin", 21, 2.64);
        Student student3 = ob.new Student("Meow", 25, 4.00);

        System.out.println(student1.name);
        System.out.println(student1.age);
        System.out.println(student1.cgpa);
        System.out.println(student1.isEnrolled);

        System.out.println(student2.name);
        System.out.println(student2.age);
        System.out.println(student2.cgpa);
        System.out.println(student2.isEnrolled);

        System.out.println(student3.name);
        System.out.println(student3.age);
        System.out.println(student3.cgpa);
        System.out.println(student3.isEnrolled);

        student1.study();
        student2.study();
        student3.study();

    }
}
