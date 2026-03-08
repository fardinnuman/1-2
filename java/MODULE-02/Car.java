// CLASS CREATION //
public class Car {
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