//https://cses.fi/problemset/task/1712

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD_MAX = 1000000007;

ll modpow(ll x, ll n){
    if (n == 0) return 1 % MOD_MAX;
    ll u = modpow(x,n/2);
    u = (u*u) % MOD_MAX;
    if (n % 2 == 1) u = (u * x) % MOD_MAX;
    return u;
}

int main(){
    ios::sync_with_stdio(0);

    ll calcAmount;
    cin >> calcAmount;

    //solve each query
    ll x, n, a;
    for (ll i = 0; i < calcAmount; i ++){
        cin >> x >> n >> a;
        cout << modpow(x,modpow(n,a)) << "\n";
    }

    return 0;
}
