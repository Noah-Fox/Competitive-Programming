//https://cses.fi/problemset/task/2189

/**
 * Use (p3-p1)x(p3-p2) = (conj(p3-p1)*(p3-p2)).Y to find cross product
*/

#include <iostream>
#include <complex>

using namespace std;

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

int main(){
    ios::sync_with_stdio(0);

    ll testAmount;
    cin >> testAmount;

    for (ll i = 0; i < testAmount; i ++){
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        P p1 = {x1,y1};
        P p2 = {x2,y2};
        P p3 = {x3,y3};

        ll cross = (conj(p3-p1) * (p3-p2)).Y;

        if (cross > 0){
            cout << "LEFT\n";
        }
        else if (cross == 0){
            cout << "TOUCH\n";
        }
        else {
            cout << "RIGHT\n";
        }
    }

    return 0;
}
