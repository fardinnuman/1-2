// Write a complete C++ program using these setters and getters

#include <iostream>
using namespace std;

class Rectangle
{

private:
    int height;
    int width;

public:
    // setters
    void setHeight(int h)
    {
        height = h;
    }
    void setWidth(int w)
    {
        width = w;
    }

    // getters
    int getHeight()
    {
        return height;
    }
    int getWidth()
    {
        return width;
    }
};

int main()
{
    Rectangle r1;

    r1.setHeight(5);
    r1.setWidth(6);

    cout << r1.getHeight() << endl;
    cout << r1.getWidth() << endl;
}