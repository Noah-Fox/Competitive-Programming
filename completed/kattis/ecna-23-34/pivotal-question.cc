//https://open.kattis.com/problems/apivotalquestion

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> values(n);
    vector<bool> valid(n,true);
    ll max = 0;
    for (ll i = 0; i < n; i ++){
        cin >> values[i];
        if (values[i] < max){
            valid[i] = false;
        }
        if (values[i] > max){
            max = values[i];
        }
    }

    ll count = 0;
    ll min = 1000001;
    for (ll i = n-1; i >= 0; i --){
        if (values[i] > min){
            valid[i] = false;
        }
        if (values[i] < min){
            min = values[i];
        }
        if (valid[i]){
            count ++;
        }
    }

    cout << count << " ";
    ll amountOutputted = 0;
    for (ll i = 0; i < n; i ++){
        if (valid[i]){
            cout << values[i] << " ";
            amountOutputted ++;
            if (amountOutputted >= 100){
                break;
            }
        }
    }
    cout << "\n";

    return 0;
}
