#include <iostream>

using namespace std;

int main()
{
    int marks = 100;

    cout << "The mark is: " << marks<<endl;

    short a;
    int b;
    long c;
    long long d;

    // float score = 45.3221;
    // double score2 = 45.3221;
    // long double score3 = 45.3221;

    // cout << "The score is: " << score<<endl;
    // cout << "The score is: " << score2<<endl;
    // cout << "The score is: " << score3<<endl;

////

    // score = 34.2;
    // cout<<score;

    // if I don't change the variable to change later I can declare it as...
    // float const store = 34.2
    // as a result, I can't change it later

    float const score = 45.3221;
    double const score2 = 45.3221;
    long double const score3 = 45.3221;

    cout << "The score is: " << score<<endl;
    cout << "The score is: " << score2<<endl;
    cout << "The score is: " << score3<<endl;

    return 0;
}