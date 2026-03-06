
// FOR TAKING INPUTS FROM USER
import java.util.Scanner;

public class Java7 {

    public static void main(String[] agrs) {

        Scanner sc = new Scanner(System.in); // OBJECT FOR TAKING INPUTS FROM USER

        // TAKING INPUTS
        System.out.print("Enter your name: ");
        String name = sc.nextLine(); // FOR FULL LINE STRING

        System.out.print("Enter your age: ");
        int age = sc.nextInt(); // FOR INTEGER

        System.out.print("Enter your nickname: ");
        String nick = sc.next(); // FOR ONE WORD STRING

        System.out.print("Enter your CGPA: ");
        double cgpa = sc.nextDouble(); // FOR DOUBLE

        System.out.print("Enter your salary: ");
        long salary = sc.nextLong(); // FOR LONG

        System.out.print("Enter your favorite letter: ");
        char letter = sc.next().charAt(0); // FOR CHARACTER*

        // SHOWING OUTPUTS
        System.out.println("\nYOUR INFORMATIONS:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Nickname: " + nick);
        System.out.println("CGPA: " + cgpa);
        System.out.println("Salary: " + salary);
        System.out.println("Letter: " + letter);
    }
}
