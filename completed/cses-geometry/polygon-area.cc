//https://cses.fi/problemset/task/2191

/**
 * using shoelace formula
*/

#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    ll x, y, x1, y1, x2, y2;
    cin >> x >> y;
    x1 = x;
    y1 = y;

    ll area = 0;
    for (ll i = 1; i < n; i ++){
        cin >> x2 >> y2;
        area += x1*y2 - x2*y1;
        x1 = x2;
        y1 = y2;
    }

    area += x1*y - x*y1;

    cout << abs(area) << "\n";

    return 0;
}
