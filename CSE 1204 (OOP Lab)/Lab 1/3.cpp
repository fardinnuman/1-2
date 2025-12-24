#include <iostream>
#include <cmath> // for sqrt
using namespace std;

class Triangle
{
private:
    int edge1, edge2, edge3;
    float area;

public:
    // Constructor to initialize edges
    Triangle(int e1, int e2, int e3) : edge1(e1), edge2(e2), edge3(e3), area(0) {}

    // Check if the edges can form a valid triangle
    bool isValid() const
    {
        return (edge1 + edge2 > edge3) &&
               (edge1 + edge3 > edge2) &&
               (edge2 + edge3 > edge1);
    }

    // Calculate area using Heron's formula
    void calculateArea()
    {
        if (isValid())
        {
            float s = (edge1 + edge2 + edge3) / 2.0;
            area = sqrt(s * (s - edge1) * (s - edge2) * (s - edge3));
        }
        else
        {
            area = 0;
        }
    }

    // Display the area
    void showArea() const
    {
        if (area > 0)
            cout << "Area of the triangle: " << area << endl;
        else
            cout << "Cannot calculate area. Invalid triangle edges." << endl;
    }

    // Display the edges
    void showEdges() const
    {
        cout << "Edges: " << edge1 << ", " << edge2 << ", " << edge3 << endl;
    }
};

int main()
{
    // Initialize a triangle
    Triangle t(3, 4, 5);

    cout << "Triangle edges:\n";
    t.showEdges();

    // Check validity
    if (t.isValid())
    {
        cout << "The edges form a valid triangle.\n";
        t.calculateArea();
        t.showArea();
    }
    else
    {
        cout << "The edges do NOT form a valid triangle.\n";
    }

    return 0;
}
