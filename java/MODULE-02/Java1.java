public class Java1 {

    public static void main(String[] args) {
        // OBJECT CREATION //
        // Scanner scanner = new Scanner(System.in);
        // Random random = new Random();
        Car car = new Car();

        // System.out.println(car); // <- MEMORY ADDRESS
        // System.out.println(car.company);
        // System.out.println(car.model);
        // System.out.println(car.year);
        // System.out.println(car.price);
        // System.out.println(car.isRunning);

        car.start();
        System.out.println(car.isRunning);

        car.drive();

        car.stop();
        System.out.println(car.isRunning);

        // BOTH OBJECTS ARE DIFFERENT BUT SHOWS THE SAME ATTRIBUTES? PROBLEM!
        Car car1 = new Car();
        Car car2 = new Car();
        System.out.println(car1.company + " " + car1.model);
        System.out.println(car2.company + " " + car2.model);

    }
}
