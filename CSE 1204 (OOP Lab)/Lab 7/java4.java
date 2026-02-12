import java.util.Scanner;
import java.util.Arrays;

public class java4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // i) Display name and address
        System.out.println("Name: Fardin Numan");
        System.out.println("Address: Rajshahi, Bangladesh");

        // ii) Take two integers and print the bigger one
        System.out.print("Enter first number: ");
        int a = sc.nextInt();
        System.out.print("Enter second number: ");
        int b = sc.nextInt();
        if (a > b)
            System.out.println("Bigger number is: " + a);
        else
            System.out.println("Bigger number is: " + b);

        // iii) Array operations
        int[] ax = new int[10];
        System.out.println("Enter 10 numbers:");
        for (int i = 0; i < 10; i++) {
            ax[i] = sc.nextInt();
        }

        // Finding largest, smallest and average
        int max = ax[0], min = ax[0], sum = 0;
        for (int i = 0; i < 10; i++) {
            if (ax[i] > max)
                max = ax[i];
            if (ax[i] < min)
                min = ax[i];
            sum += ax[i];
        }
        double avg = sum / 10.0;
        System.out.println("Largest: " + max);
        System.out.println("Smallest: " + min);
        System.out.println("Average: " + avg);

        // Searching for a number
        System.out.print("Enter a number to search: ");
        int key = sc.nextInt();
        boolean found = false;
        for (int i = 0; i < 10; i++) {
            if (ax[i] == key) {
                found = true;
                break;
            }
        }
        if (found)
            System.out.println(key + " is found in the array.");
        else
            System.out.println(key + " is not found in the array.");

        // Sorting array
        Arrays.sort(ax);
        System.out.println("Sorted array:");
        for (int i = 0; i < 10; i++) {
            System.out.print(ax[i] + " ");
        }
        System.out.println();

        sc.close();
    }
}
