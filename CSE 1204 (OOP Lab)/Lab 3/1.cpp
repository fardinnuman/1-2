#include <iostream>
using namespace std;

// Father class
class Father {
private:
    int money;
protected:
    int gold;
public:
    int land;

public:
    Father() { money = 100; gold = 50; land = 200; } // To initialize values
};

// Son class inheriting from Father
class Son : public Father { // To change public into protected/private
public:
    void showSon() {
        // money; // Not accessible
        cout << "gold in Son: " << gold << endl;  // Accessible
        cout << "land in Son: " << land << endl;  // Accessible
    }
};

// GrandSon class inheriting from Son
class GrandSon : public Son { // To change public into protected/private
public:
    void showGrandSon() {
        // money; // Not accessible
        cout << "gold in GrandSon: " << gold << endl;
        cout << "land in GrandSon: " << land << endl;

        int sum = gold + land; // money not accessible
        cout << "Sum of accessible members: " << sum << endl;
    }
};

int main() {
    Son s;
    GrandSon gs;

    s.showSon();
    gs.showGrandSon();

    return 0;
}
