public class Java9 {
    public static void main(String[] args) {

        int[] arr = { 1, 2, 3 };

        // System.out.println(arr[3]); // THIS LINE IS INCORRECT! BUT THE FOLLOWING 3 LINES ARE NOT, YET THE PROGRAM WILL STOP BECAUSE OF THE 1 WRONG LINE, AND WONT SHOW THE CORRECT 3 LINES. SOLUTION? "try-catch"
        // System.out.println(arr[0]);
        // System.out.println(arr[1]);
        // System.out.println(arr[2]);

        try {
            System.out.println(arr[3]); // <- WE WRITE RISKY LINES INSIDE try WHICH CAN POSSIBLY THROW ERRORS
        } catch (Exception e) {
            System.out.println(e); // <- WE WRITE HANDLING LINES INSIDE catch WHICH WILL RUN IF try THROWS ERRORS
        }

        System.out.println(arr[0]);
        System.out.println(arr[1]);
        System.out.println(arr[2]);

    }
}