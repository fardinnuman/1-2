package cse1204;

import java.util.Scanner;

public class p4_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        if (a > b)
            System.out.println("Bigger number: " + a);
        else
            System.out.println("Bigger number: " + b);
    }
}
