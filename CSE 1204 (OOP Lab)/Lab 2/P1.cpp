#include <iostream>
using namespace std;

class Test {
private:
    int x, y;
    static int z;   // To count total objects

public:
    // Empty constructor
    Test() {
        x = 0;
        y = 0;
        z++;
    }

    // Parameterized constructor
    Test(int a, int b) {
        x = a;
        y = b;
        z++;
    }

    // Copy constructor
    Test(const Test &t) {
        x = t.x;
        y = t.y;
        z++;
    }

    // Method to initialize x and y
    void setData(int a, int b) {
        x = a;
        y = b;
    }

    // To display only z
    static void showZ() {
        cout << "Total objects: " << z << endl;
    }

    // To display x, y, z
    void showData() const {
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    // Destructor
    ~Test() {}
};

int Test::z = 0;

int main() {
    Test t1, t2(3,4), t3(t2), t4(5,6), t5(1,9);

    Test::showZ();

    int sumX = t1.getX() + t2.getX() + t3.getX() + t4.getX() + t5.getX();
    cout << "Sum of x: " << sumX << endl;

    Test arr[5] = {t1, t2, t3, t4, t5};
    int maxY = arr[0].getY(), index = 0;

    for(int i=1;i<5;i++) {
        if(arr[i].getY() > maxY) {
            maxY = arr[i].getY();
            index = i;
        }
    }

    cout << "Object number with max y: " << index+1 << endl;
    return 0;
}
