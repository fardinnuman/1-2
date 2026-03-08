public class Java2 {
    public static void main(String[] args) {

        Student student1 = new Student("Numan", 20, 3.39);
        Student student2 = new Student("Fardin", 21, 2.64);
        Student student3 = new Student("Meow", 25, 4.00);

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
