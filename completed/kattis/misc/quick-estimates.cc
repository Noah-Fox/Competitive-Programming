//https://open.kattis.com/contests/w9i5jp/problems/quickestimate

// #include <iostream>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    string num;
    for (ll i = 0; i < n; i ++){
        cin >> num;
        cout << num.length() << "\n";
    }

    return 0;
}
