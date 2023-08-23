//https://cses.fi/problemset/task/1729

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll n, moveAmount;
    cin >> n >> moveAmount;

    //input moves
    vector<ll> moves(moveAmount);
    for (ll i = 0; i < moveAmount; i ++){
        cin >> moves[i];
    }

    //solve
    vector<ll> winningStates(n+1,false);
    for (auto it = moves.begin(); it != moves.end(); it ++){
        winningStates[*it] = true;
    }
    for (ll i = 1; i <= n; i ++){
        if (!winningStates[i]){
            cout << "L";
            for (auto it = moves.begin(); it != moves.end(); it ++){
                if (i + *it <= n){
                    winningStates[i + *it] = true;
                }
            }
        }
        else {
            cout << "W";
        }
    }
    cout << "\n";

    return 0;
}
