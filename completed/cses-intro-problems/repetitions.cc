//https://cses.fi/problemset/task/1069

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string seq;
    cin >> seq;

    ll maxSeq = 0;
    ll onSeq = 1;

    for (ll i = 1; i < seq.length(); i ++){
        if (seq[i] != seq[i-1]){
            maxSeq = max(maxSeq,onSeq);
            onSeq = 1;
        }
        else {
            onSeq ++;
        }
    }
    maxSeq = max(maxSeq,onSeq);

    cout << maxSeq << "\n";

    return 0;
}
