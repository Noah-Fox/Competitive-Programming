//https://cses.fi/problemset/task/1082

/**
 * Find the sum of divisors of all numbers from 1 to n
 *
 * Uses the function sumN(x), which finds the sum of all numbers 1 to x, using modular arithmetic
 *
 * Sum begins as the sum of all 1's and each number, which is equal to n + sumN(n) - 1
 *
 * Then, for each i = 2 -> sqrt(n):
 *      - Add i to the sum for every multiple of i from i to n
 *          - i * floor((n - i*i)/i + 1)
 *      - Add every number from i+1 to n/i
 *          - sumN(n/i) - sumN(i)
*/

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 1000000007;

ll sumN(ll x){
    ll x2 = x + 1;
    if (x % 2 == 0){
        x /= 2;
    }
    else {
        x2 /= 2;
    }
    return ((x % MAX) * (x2 % MAX)) % MAX;
}

ll modMult(ll a, ll b){
    return ((a % MAX) * (b % MAX)) % MAX;
}

ll modAdd(ll a, ll b){
    return ((a % MAX) + (b % MAX)) % MAX;
}

int main(){
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    // ll sum = 0;
    // for (ll i = 1; i <= n; i ++){
    //     ll amount = n / i;
    //     ll add = ((amount % MAX) * (i % MAX)) % MAX;
    //     sum = ((sum % MAX) + add) % MAX;
    // }

    // cout << sum << "\n";

    ll sum = (n-1) % MAX;
    sum += sumN(n);

    for (ll i = 2; i*i <= n; i ++){
        ll a = ((n - i*i) / i) + 1;
        sum = modAdd(sum, modMult(i, a));

        sum = modAdd(sum, sumN(n/i) - sumN(i));
    }

    cout << sum << "\n";

    return 0;
}
