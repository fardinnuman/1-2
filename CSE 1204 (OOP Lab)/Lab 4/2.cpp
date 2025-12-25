#include <iostream>
using namespace std;

class Circuit {
private:
    float real;
    float img;

public:
    // Constructor to initialize real and imaginary
    Circuit(float r = 0, float i = 0) {
        real = r;
        img = i;
    }
    // Operator overloading for addition
    Circuit operator+(Circuit c) {
        return Circuit(real + c.real, img + c.img);
    }
    // Operator overloading for division
    Circuit operator/(Circuit c) {
        float d = c.real*c.real + c.img*c.img;
        return Circuit(
            (real*c.real + img*c.img)/d,
            (img*c.real - real*c.img)/d
        );
    }
    // To display real and imaginary values
    void display() {
        cout << real << " + j" << img << endl;
    }
};

int main() {
    // To initialize impedance values
    Circuit z1(3,4), z2(4,-3), z3(0,6);
    // Input voltage
    Circuit v(100,50);
    // Current calculation
    Circuit i = v / (z1 + z2 + z3);
    i.display();
    return 0;
}
