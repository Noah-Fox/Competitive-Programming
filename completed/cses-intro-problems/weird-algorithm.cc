//https://cses.fi/problemset/task/1068

#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll onNum;
    cin >> onNum;

    while (onNum != 1){
        cout << onNum << " ";
        if (onNum % 2 == 0){
            onNum /= 2;
        }
        else {
            onNum = 3 * onNum + 1;
        }
    }
    cout << "1\n";

    return 0;
}
