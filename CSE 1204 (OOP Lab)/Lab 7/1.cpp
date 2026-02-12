class Test
{
private:
    int x;

protected:
    int y;

public:
    int z;

public:
    void SetData(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }

    float getAverage()
    {
        return (x + y + z) / 3.0;
    }
};
