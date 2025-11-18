/*
Write a Triangle class with 3 edges as data members and methods. The
structure of the Tringle class is:

class Triangle {
    int edge1;
    int edge2;
    int edge3;
    float area;
    // write methods;
}

Now do the following
i) Initialize edges of a triangle
ii) Find area of the triangle
iii) Check whether the 3 edges form a triangle
*/

#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    int edge1, edge2, edge3;
    float area;

public:
    Triangle(int a, int b, int c)
    {
        edge1 = a;
        edge2 = b;
        edge3 = c;
        area = 0;
    }

    bool isValid()
    {
        return (edge1 + edge2 > edge3 &&
                edge1 + edge3 > edge2 &&
                edge2 + edge3 > edge1);
    }

    void calculateArea()
    {
        if (isValid())
        {
            float s = (edge1 + edge2 + edge3) / 2.0;
            area = sqrt(s * (s - edge1) * (s - edge2) * (s - edge3));
        }
        else
        {
            cout << "Not a valid triangle." << endl;
        }
    }

    float getArea()
    {
        return area;
    }
};

int main()
{

    Triangle t(3, 4, 5);

    if (t.isValid())
    {
        cout << "Valid triangle." << endl;

        t.calculateArea();
        cout << "Area: " << t.getArea() << endl;
    }
    else
    {
        cout << "Invalid triangle." << endl;
    }

    return 0;
}
