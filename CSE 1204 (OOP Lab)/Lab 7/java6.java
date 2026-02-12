class TestStatic {
    static int staticVar = 100; // Static variable
    int nonStaticVar = 50; // Non-static variable

    static void staticMethod() {
        System.out.println("Inside static method.");

        // Accessing static variable - Allowed
        System.out.println("Static variable: " + staticVar);

        // Accessing non-static variable - Not allowed directly
        // System.out.println("Non-static variable: " + nonStaticVar);

        // Accessing non-static variable using object
        TestStatic obj = new TestStatic();
        System.out.println("Non-static variable via object: " + obj.nonStaticVar);
    }

    void nonStaticMethod() {
        System.out.println("Inside non-static method.");
        System.out.println("Access static variable: " + staticVar); // Allowed
        System.out.println("Access non-static variable: " + nonStaticVar); // Allowed
    }
}

public class java6 {
    public static void main(String[] args) {
        // Call static method without creating object
        TestStatic.staticMethod();

        // Call non-static method using object
        TestStatic obj = new TestStatic();
        obj.nonStaticMethod();
    }
}

