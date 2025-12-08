#include <iostream>
using namespace std;

class Remote {
private:
    int sound;
public:
    Remote(int s = 0){
        sound = s;
    }
    Remote operator++(){
        sound++;
        return *this;
    }
    Remote operator--(){
        sound--;
        return *this;
    }
    void Display(){
        cout << "Sound = " << sound << endl;
    }
};
int main(){
    Remote rs;
    ++rs;
    ++rs;
    --rs;
    rs.Display();
    return 0;
}
