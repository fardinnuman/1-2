#include<iostream>

using namespace std;

class Baba{
private:
    int money;

protected:
    int gold;

public:
    int land;

    Baba(){
        money = 100000;
        gold = 200;
        land = 3;
    }

    int getMoney(){
        return money;
    }
};

class Chele : public Baba{
public:
    void accessChele(){
        cout << "\n~Access from Chele Class~\n";
        cout << "money: NOT ACCESSIBLE\n";
        cout << "gold: Accessible= " << gold << endl;
        cout << "land: Accessible= " << land << endl;
    }
};
class Nati : public Chele{
public:
    void accessNati(){
        cout << "\n~Access from Nati Class~\n";
        cout << "money: NOT ACCESSIBLE\n";
        cout << "gold: Accessible= " << gold << endl;
        cout << "land: Accessible= " << land << endl;
    }
    int sumAll(){
        return getMoney() + gold + land;
    }
};
int main(){
    Chele s;
    Nati g;

    s.accessChele();
    g.accessNati();

    cout << "Sum of money + gold + land (from Nati): "
         << g.sumAll() << endl;

    return 0;
}
