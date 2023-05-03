//https://cses.fi/problemset/task/1635

#include <iostream>
#include <vector>
#include <map>
// #include <bits/stdc++.h>

using namespace std;

int recurse(const vector<int>& coins, int sum, map<int,int>& memo){
    if (sum < 0){
        return 0;
    }
    if (sum == 0){
        return 1;
    }

    if (memo.count(sum)){
        cout << "memo " << sum << "\n";;
        return memo[sum];
    }

    int count = 0;
    for (int i = 0; i < coins.size(); i ++){
        count += recurse(coins,sum-coins[i],memo);
    }
    memo[sum] = count;
    return count;
}

int main(){
    ios::sync_with_stdio(0);

    int coinAmount, sum;
    cin >> coinAmount >> sum;
    vector<int> coins(coinAmount);
    map<int,int> memo;

    for (int i = 0; i < coinAmount; i ++){
        cin >> coins[i];
    }

    cout << recurse(coins,sum,memo) << "\n";

    return 0;
}
