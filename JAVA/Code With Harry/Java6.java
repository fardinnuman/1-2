public class Java6 {

    public static void main(String[] args) {

        // FOR LOOP //
        for (int i = 0; i < 10; i++) {
            System.out.println("FOR LOOP " + i);
        }

        // WHILE LOOP //
        int j = 0;
        while (j < 10) {
            System.out.println("WHILE LOOP " + j);
            j++;
        }

        // DO-WHILE LOOP //
        int k = 0;
        do {
            System.out.println("DO-WHILE LOOP " + k);
            k++;
        } while (k < 10);

        System.out.println("\nIN A SINGLE LINE:");

        // FOR LOOP //
        System.out.print("\nFOR LOOP: ");
        for (int l = 0; l < 10; l++) {
            System.out.print(l + " ");
        }

        // WHILE LOOP //
        System.out.print("\nWHILE LOOP: ");
        int m = 0;
        while (m < 10) {
            System.out.print(m + " ");
            m++;
        }

        // DO-WHILE LOOP //
        System.out.print("\nDO-WHILE LOOP: ");
        int n = 0;
        do {
            System.out.print(n + " ");
            n++;
        } while (n < 10);
    }
}