//https://cses.fi/problemset/task/1634

// #include <iostream>
// #include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int coinAmount, coinSum;

    cin >> coinAmount >> coinSum;
    vector<int> coins(coinAmount);
    vector<int> combos(coinSum+1,0);

    for (int i = 0; i < coinAmount; i ++){
        cin >> coins[i];
        if (coins[i] <= coinSum){
            combos[coins[i]] = 1;
        }
    }

    for (int i = 1; i <= coinSum; i ++){
        if (combos[i] > 0){
            for (int x = 0; x < coinAmount; x ++){
                if (i+coins[x] <= coinSum && (combos[i+coins[x]] == 0 || combos[i]+1 < combos[i+coins[x]])){
                    combos[i+coins[x]] = combos[i]+1;
                }
            }
        }
    }

    if (combos[coinSum] == 0){
        cout << "-1\n";
    }
    else {
        cout << combos[coinSum] << "\n";
    }


    return 0;
}
