//https://cses.fi/problemset/task/1081

/**
 * Find the largest gcd of any pair in a list
 *
 * Store each value in an unordered set. Record the largest number that there is more than one of
 *
 * iterate from half the largest number to 1. For each number, iterate each multiple of it to the largest
 * number. If more than one of these multiples is in the set, it is the highest gcd
*/

// #include <iostream>
// #include <vector>
// #include <set>
// #include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll numAmount;
    cin >> numAmount;

    //input numbers into a set
    unordered_set<ll> nums;
    ll maxNum = 0;
    ll maxDouble = 0;
    ll a;
    for (ll i = 0; i < numAmount; i ++){
        cin >> a;
        if (nums.count(a) > 0){
            maxDouble = max(maxDouble,a);
        }
        else{
            maxNum = max(maxNum,a);
            nums.insert(a);
        }
    }

    //solve
    for (ll i = 0.5*maxNum; i > 0; i --){
        if (maxDouble > i){
            cout << maxDouble << "\n";
            return 0;
        }
        ll count = 0;
        for (ll j = i; j <= maxNum; j += i){
            count += nums.count(j);
            if (count > 1){
                cout << i << "\n";
                return 0;
            }
        }
    }

    return 0;
}
