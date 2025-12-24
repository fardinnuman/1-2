#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle(int r) : radius(r) {} // Constructor with initializer list

    float getArea() const
    {
        return 3.14159 * radius * radius; // Calculate area on demand
    }
};

int main()
{
    Circle c1(2), c2(3), c3(5);

    float total = c1.getArea() + c2.getArea() + c3.getArea();

    cout << "Area of circle 1: " << c1.getArea() << endl;
    cout << "Area of circle 2: " << c2.getArea() << endl;
    cout << "Area of circle 3: " << c3.getArea() << endl;
    cout << "Total area of three circles: " << total << endl;

    return 0;
}
