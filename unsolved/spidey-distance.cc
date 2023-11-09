//https://open.kattis.com/contests/w9i5jp/problems/spideydistance

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll twiceSpidey(ll x, ll y){
    return 2 * abs(x - y) + 3 * (min(x,y) - 1);
}

ll getTheMax(ll x, ll y){
    if (x > y) return x;
    return y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll taxiDist, spideyDist;
    cin >> taxiDist >> spideyDist;

    //find spidey count
    ll y = spideyDist;
    ll spideyCount = 0;
    ll taxiCount = 0;
    for (ll x = 2; x <= spideyDist; x ++){
        while (twiceSpidey(x,y) > 2*spideyDist){
            y --;
        }
        spideyCount += y-1;
        ll taxiY = getTheMax(0,taxiDist - x + 2);
        cout << x << " " << y << " " << taxiY << "\n";
        if (taxiY > y){
            taxiCount += y-1;
        }
        else if (taxiY > 0) {
            taxiCount += taxiY-1;
        }
    }
    cout << taxiCount << " " << spideyCount << "\n";

    spideyCount *= 4;
    spideyCount += 4*spideyDist + 1;
    taxiCount *= 4;
    taxiCount += 4*taxiDist + 1;

    cout << taxiCount << " " << spideyCount << "\n";

    //find taxi count
    // ll taxiCount = 4*taxiDist + 1 + 2*taxiDist*(taxiDist-1);

    //simplify
    if (taxiCount >= spideyCount){
        cout << "1\n";
        return 0;
    }
    for (ll i = 2; i*i <= taxiCount; i ++){
        while (taxiCount % i == 0 && spideyCount % i == 0){
            taxiCount /= i;
            spideyCount /= i;
        }
    }

    //output solution
    cout << taxiCount << "/" << spideyCount << "\n";

    return 0;
}
