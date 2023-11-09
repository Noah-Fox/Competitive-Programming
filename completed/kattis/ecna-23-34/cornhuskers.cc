//https://open.kattis.com/problems/cornhusker

// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll sum = 0, a, b;
    for (ll i = 0; i < 5; i ++){
        cin >> a >> b;
        sum += a * b;
    }
    sum /= 5;

    cin >> a >> b;
    sum *= a;
    sum /= b;

    cout << sum << "\n";

    return 0;
}
