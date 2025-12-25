#include <iostream>
using namespace std;

class Remote {
private:
    int sound;

public:
    Remote() {
        sound = 0;
    } // To initialize sound value

    void operator++() {
        sound++;
    } // To increase sound

    void operator--() {
        sound--;
    } // To decrease sound
    
    void display() {
        cout << sound << endl;
    } // To display sound value
};

int main() {
    Remote rs;
    ++rs; // Increase
    ++rs; 
    --rs; // Decrease
    rs.display();
    return 0;
}

