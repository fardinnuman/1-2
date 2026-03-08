import java.util.Scanner;

public class Java11 {

    public static void main(String[] args) {

        float num1, num2;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first number: ");
        num1 = scanner.nextFloat();

        System.out.print("Enter second number: ");
        num2 = scanner.nextFloat();

        char op;
        System.out.print("Enter operator: ");
        op = scanner.next().charAt(0);

        switch (op) {

            case '+':
                System.out.println(num1 + num2);
                break;
            case '-':
                System.out.println(num1 - num2);
                break;
            case '*':
                System.out.println(num1 * num2);
                break;
            case '/':
                System.out.println(num1 / num2);
                break;
            case '%':
                System.out.println(num1 % num2);
                break;
            default:
                System.out.println("Invalid operator");
                break;

        }

    }

}
