//https://codeforces.com/contest/189/problem/A

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    vector<ll> lengths(3);
    cin >> n >> lengths[0] >> lengths[1] >> lengths[2];

    vector<ll> maxLengths(n+1,-1);
    maxLengths[0] = 0;
    for (ll i = 0; i <= n; i ++){
        ll localMax = 0;
        for (ll j = 0; j < 3; j ++){
            if (lengths[j] <= i){
                localMax = max(localMax,maxLengths[i-lengths[j]]+1);
            }
        }
        if (localMax > 0){
            maxLengths[i] = localMax;
        }
    }

    // for (ll i = 0; i <= n; i ++){
    //     cout << maxLengths[i] << " ";
    // }
    // cout << "\n";
    cout << maxLengths[n] << "\n";

    return 0;
}
