// POLYMORPHISM
//    1. Compile Time Polymorphism -> Function Overloading

public class Java3 {

    void displayInfo(String name) {
        System.out.println(name);
    }

    void displayInfo(int age) {
        System.out.println(age);
    }

    void displayInfo(String name, int age) {
        System.out.println(name);
        System.out.println(age);
    }

    public static void main(String[] args) {

        Java3 ob = new Java3();

        ob.displayInfo("Numan");
        ob.displayInfo(20);
        ob.displayInfo("Numan", 20);

    }

}
