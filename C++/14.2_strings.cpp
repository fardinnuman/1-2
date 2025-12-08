#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Fardin Numan";

    cout << "The substring of name is: " << name.substr(0, 3) << endl; // 0 to 3-1=2 -> Far
    cout << "The substring of name is: " << name.substr(0, 1) << endl; // 0 to 1-1=0 -> F
    cout << "The substring of name is: " << name.substr(0, 8) << endl; // 0 to 8-1=7 -> Fardin N
    cout << "The substring of name is: " << name.substr(1, 1) << endl; // 1 to 1-1=0 -> a
                                                     // ^  ^ -> Index 
    return 0;
}