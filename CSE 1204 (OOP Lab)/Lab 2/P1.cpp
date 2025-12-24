#include <iostream>
using namespace std;

class Test {
private:
    int x, y;
    static int z;

public:
    Test() {
        x = 0;
        y = 0;
        z++;
    }

    Test(int a, int b) {
        x = a;
        y = b;
        z++;
    }

    Test(const Test &obj) {
        x = obj.x;
        y = obj.y;
        z++;
    }

    void setXY(int a, int b) {
        x = a;
        y = b;
    }

    static void showZ() {
        cout << "Total objects created = " << z << endl;
    }

    void display() const {
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    ~Test() {
    }
};

int Test::z = 0;

int main() {

    Test o1;              
    Test o2(5, 12);       
    Test o3(o2);          
    Test o4; 
    o4.setXY(7, 3);       
    Test o5(9, 14);

    o1.display();
    o2.display();
    o3.display();
    o4.display();
    o5.display();

    Test::showZ();

    int sumX = o1.getX() + o2.getX() + o3.getX() + o4.getX() + o5.getX();
    cout << "Sum of all x = " << sumX << endl;

    int maxY = o1.getY();
    int objNo = 1;

    Test arr[5] = {o1, o2, o3, o4, o5};

    for (int i = 0; i < 5; i++) {
        if (arr[i].getY() > maxY) {
            maxY = arr[i].getY();
            objNo = i + 1;
        }
    }

    cout << "Object number with maximum y = " << objNo << endl;

    return 0;
}
