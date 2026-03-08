class Student {
    String name;
    int age;

    void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class Java3 {
    public static void main(String[] args) {
        Student s1 = new Student();  // create object
        s1.name = "Numan";
        s1.age = 19;
        s1.displayInfo();            // call method
    }
}