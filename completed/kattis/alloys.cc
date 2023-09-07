//https://open.kattis.com/problems/alloys

#include <iostream>

using namespace std;

typedef long double ld;

int main(){
    ld p;
    cin >> p;
    if (p > 1) p = 1;
    ld h = p * p / 4;
    cout << h << "\n";

    return 0;
}
