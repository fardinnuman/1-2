public class Student {
    String name;
    int age;
    double cgpa;
    boolean isEnrolled;

    Student(String name, int age, double cgpa) {
        this.name = name;
        this.age = age;
        this.cgpa = cgpa;
    }
    // this -> REFERS TO THE OBJECT WE ARE CURRENTLY WORKING WITH

    // WHEN WE CREATE student1, this = student1
    // SO IT BECOMES, student1.name = name; student1.age = age; student1.cgpa = cgpa;
    // WHEN WE CREATE student2, this = student2
    // SO IT BECOMES, student2.name = name; student2.age = age; student2.cgpa = cgpa;

}

// public class Student {
//     String name;
//     int age;
//     double cgpa;
//     boolean isEnrolled;

//     BTW, PARAMETERS' NAME DOESN'T NECESSARILY NEED TO BE SAME AS THE ATTRIBUTES' NAME. THO, KEEPING SAME IS BETTER
//     Student(String x, int y, double z) {
//     this.name = x;
//     this.age = y;
//     this.cgpa = z;
//     }

// }