import java.util.ArrayList;
import java.util.Collections;

public class Java1 {
    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();

        // i) add()
        list.add(10);
        list.add(30);
        list.add(20);
        System.out.println("After add(): " + list);

        // ii) get()
        System.out.println("Element at index 1 (get): " + list.get(1));

        // iii) set()
        list.set(1, 50);
        System.out.println("After set(): " + list);

        // iv) remove()
        list.remove(0);
        System.out.println("After remove(): " + list);

        // v) size()
        System.out.println("Size of list: " + list.size());

        // vi) toString()
        System.out.println("List (toString): " + list.toString());

        // vii) sort()
        Collections.sort(list);
        System.out.println("After sort(): " + list);

        // viii) clear()
        list.clear();
        System.out.println("After clear(): " + list);
    }
}


