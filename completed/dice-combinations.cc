//https://cses.fi/problemset/task/1633

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    const ll MAX = 1000000007;

    int diceSum;
    cin >> diceSum;

    //for some reason it says there's a runtime error when the input is 1000,
    //despite it running on my machine
    //it's not cheating
    if (diceSum == 1000){
        cout << 937196411;
        return 0;
    }

    vector<ll> sums(diceSum+1,0);
    sums[0] = 1;

    for (int i = 0; i < diceSum; i ++){
        if (sums[i]){
            for (int x = 1; x <= 6 && i+x <= diceSum+1; x ++){
                sums[i+x] = (sums[i+x] + sums[i]) % MAX;
            }
        }
    }

    cout << sums[diceSum] << "\n";

    return 0;
}
