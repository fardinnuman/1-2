class TestPrivate {
    private void displayMessage() {
        System.out.println("This is a private method.");
    }

    public void callPrivateMethod() {
        // Private method can be called within the class
        displayMessage();
    }
}

public class java5 {
    public static void main(String[] args) {
        TestPrivate obj = new TestPrivate();

        // Calling private method from outside the class
        // obj.displayMessage(); // Error: displayMessage() has private access

        // Calling private method indirectly using public method
        obj.callPrivateMethod(); // Works fine
    }
}

