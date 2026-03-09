class Car {
    String name;
    int year;

    Car() {
        System.out.println("Hi I am default constructor");
    }

    Car(String name, int year) {
        this.name = name;
        this.year = year;
        System.out.println("Hi I am parammeterized constructor");
    }

}

public class Java3 {

    public static void main(String[] args) {

        Car car1 = new Car();

        Car car2 = new Car("Numan", 2005);

    }

}
