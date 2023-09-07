//https://open.kattis.com/problems/nonprimefactors

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    const ll MAX = 2000001;
    vector<ll> sieve(MAX,1);
    vector<ll> primeAmount(MAX,0);

    //create sieve
    for (ll i = 2; i < MAX; i ++){
        if (primeAmount[i] == 0){
            for (ll x = 2*i; x < MAX; x += i){
                primeAmount[x] ++;
                ll y = x;
                ll multAmount = 1;
                while (y % i == 0){
                    multAmount ++;
                    y /= i;
                }
                sieve[x] *= multAmount;
            }
        }
    }

    ll queryAmount;
    cin >> queryAmount;

    ll q;
    for (ll i = 0; i < queryAmount; i ++){
        cin >> q;
        cout << sieve[q] - primeAmount[q] << "\n";
    }

    return 0;
}
