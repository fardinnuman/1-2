/*
Write a circle class with following data members and methods. The structure of the circle class is:

class Circle {
private:
    int radius;
    float area;
    // Write methods
};

Now do the following:
i) Initialize radius of 3 circles
ii) Find area of all of them
iii) Find the total area
*/

#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;
    float area;

public:
    Circle(int r)
    {
        radius = r;
        area = 0;
    }

    void calculateArea()
    {
        area = 3.14 * radius * radius;
    }

    float getArea()
    {
        return area;
    }
};

int main()
{
    Circle c1(2), c2(3), c3(5);

    c1.calculateArea();
    c2.calculateArea();
    c3.calculateArea();

    float total = c1.getArea() + c2.getArea() + c3.getArea();

    cout << "Area of cirle 1: " << c1.getArea() << endl;
    cout << "Area of cirle 2: " << c2.getArea() << endl;
    cout << "Area of cirle 3: " << c3.getArea() << endl;
    cout << "Total Area of three circles: " << total << endl;
}
