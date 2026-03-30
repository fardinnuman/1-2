public class Java2 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static Point MidPoint(Point p1, Point p2) {
        return new Point(
                (p1.x + p2.x) / 2,
                (p1.y + p2.y) / 2);
    }

    public static void main(String[] args) {

        Point p1 = new Point(2, 4);
        Point p2 = new Point(6, 8);

        Point mid = MidPoint(p1, p2);

        System.out.println("Midpoint: (" + mid.x + ", " + mid.y + ")");
    }
}