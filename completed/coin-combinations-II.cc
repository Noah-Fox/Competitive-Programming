//https://cses.fi/problemset/task/1636/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    int coinAmount, sum;
    cin >> coinAmount >> sum;

    vector<int> coins(coinAmount);
    for (int i = 0; i < coinAmount; i ++){
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end());

    vector<ll> sums(sum+1,0);
    sums[0] = 1;

    for (int x = 0; x < coinAmount; x ++){
        for (int i = 0; i < sum && i+coins[x] <= sum; i ++){
            if (sums[i] > 0){
                sums[i+coins[x]] += sums[i];
                sums[i+coins[x]] = sums[i+coins[x]] % 1000000007;
            }
        }
    }

    // for (int i = 0; i < sum; i ++){
    //     if (sums[i] > 0){
    //         for (int x = 0; x < coinAmount && i+coins[x] <= sum; x ++){
    //             sums[i+coins[x]] += sums[i];
    //             sums[i+coins[x]] = sums[i+coins[x]] % 1000000007;
    //         }
    //     }
    // }

    cout << sums[sum] << "\n";

    return 0;
}
