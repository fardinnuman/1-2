import java.util.Scanner;

public class jsd1 {

    public static void main(String[] agrs) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = sc.nextLine();

        System.out.print("Enter your age: ");
        int age = sc.nextInt();

        System.out.print("Enter your nickname: ");
        String nick = sc.next();

        System.out.print("Enter your CGPA: ");
        double cgpa = sc.nextDouble();

        System.out.print("Enter your salary: ");
        long salary = sc.nextLong();

        System.out.println("YOUR INFORMATIONS:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Nickname: " + nick);
        System.out.println("CGPA: " + cgpa);
        System.out.println("Salary: " + salary);

    }
}
