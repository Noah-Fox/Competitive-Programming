//icpc pacnw 22-23 regionals

#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll wordAmount;
    int div;
    cin >> wordAmount >> div;

    ll word = 0;
    ll tenPow = 10;
    ll count = 0;
    for (ll i = 1; i <= wordAmount; i ++){
        word = word % div;
        if (i == tenPow){
            tenPow *= 10;
        }
        word *= (tenPow % div);
        word = word % div;
        word += (i % div);
        word = word % div;
        if (word == 0){
            count ++;
        }
    }

    cout << count << "\n";

    return 0;
}
