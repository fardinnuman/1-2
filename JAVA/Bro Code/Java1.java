public class Java1 {

    // CLASS CREATION //
    class Car {
        String company = "Bugatti";
        String model = "Chiron";
        int year = 2022;
        double price = 3000000.50;
        boolean isRunning = false;

        void start() {
            isRunning = true;
            System.out.println("ENGINE STARTED");
        }

        void stop() {
            isRunning = false;
            System.out.println("ENGINE STOPPED");
        }

        void drive() {
            System.out.println("YOU ARE DRIVING THE " + model + " BY " + company + " MADE IN " + year);
        }
    }

    //

    public static void main(String[] args) {
        // OBJECT CREATION //
        // Scanner scanner = new Scanner(System.in);
        // Random random = new Random();

        Java1 ob = new Java1();

        Car car = ob.new Car();

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
        Car car1 = ob.new Car();
        Car car2 = ob.new Car();
        System.out.println(car1.company + " " + car1.model);
        System.out.println(car2.company + " " + car2.model);

    }
}
