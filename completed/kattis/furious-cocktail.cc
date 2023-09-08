//https://open.kattis.com/problems/cocktail

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll rangeAmount, drinkTime;
    cin >> rangeAmount >> drinkTime;

    //input ranges
    vector<ll> ranges(rangeAmount);
    for (ll i = 0; i < rangeAmount; i ++){
        cin >> ranges[i];
    }

    //sort ranges
    sort(ranges.begin(),ranges.end());

    //go through ranges highest to lowest
    ll startingAt = 0;
    ll minEnding = 1000000007;
    for (ll i = rangeAmount-1; i >= 0; i --){
        startingAt += drinkTime;
        ll end = startingAt + ranges[i];
        if (startingAt >= minEnding){
            cout << "NO\n";
            return 0;
        }
        minEnding = min(minEnding,end);
    }

    cout << "YES\n";

    return 0;
}
