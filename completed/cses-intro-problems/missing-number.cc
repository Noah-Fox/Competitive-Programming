//https://cses.fi/problemset/task/1083

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll sum = n;
    ll inSum = 0;

    for (ll i = 1; i < n; i ++){
        sum += i;
        ll x;
        cin >> x;
        inSum += x;
    }

    cout << sum - inSum << "\n";

    return 0;
}
