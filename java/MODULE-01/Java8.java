public class Java8 {
    public static void main(String[] args) {

        System.out.println("INTEGERS");
        int[] arr1 = { 1, 2, 3 };
        System.out.println(arr1[0]);
        System.out.println(arr1[1]);
        System.out.println(arr1[2]);

        System.out.println("FLOATS");
        float[] arr2 = { 1.5f, 2.3f, 3.6f };
        System.out.println(arr2[0]);
        System.out.println(arr2[1]);
        System.out.println(arr2[2]);

        System.out.println("CHARACTERS");
        char[] arr3 = { 'a', 'c', 'c' };
        System.out.println(arr3[0]);
        System.out.println(arr3[1]);
        System.out.println(arr3[2]);

        System.out.println("STRINGS");
        String[] arr4 = { "Mr", "Fardin", "Numan" };
        System.out.println(arr4[0]);
        System.out.println(arr4[1]);
        System.out.println(arr4[2]);

        System.out.println("2D");
        int[][] arr5 = { { 1, 2, 3 }, { 4, 5, 6 } };
        System.out.println(arr5[0][0] + " " + arr5[1][0]);
        System.out.println(arr5[0][1] + " " + arr5[1][1]);
        System.out.println(arr5[0][2] + " " + arr5[1][2]);

        System.out.println("3D");
        int[][] arr6 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        System.out.println(arr6[0][0] + " " + arr6[1][0] + " " + arr6[2][0]);
        System.out.println(arr6[0][1] + " " + arr6[1][1] + " " + arr6[2][1]);
        System.out.println(arr6[0][2] + " " + arr6[1][2] + " " + arr6[2][2]);

        System.out.println("FOR LOOP");
        int[] arr7 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        for (int i = 0; i < arr7.length; i++) {
            System.out.println(arr7[i]);
        }

        System.out.println("FOR-EACH LOOP");
        int[] arr8 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        for (int value : arr8) {
            System.out.println(value);
        }

    }
}
