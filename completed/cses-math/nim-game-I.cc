//https://cses.fi/problemset/task/1730

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll testAmount;
    cin >> testAmount;
    
    ll heapAmount;
    for (ll i = 0; i < testAmount; i ++){
        cin >> heapAmount;
        ll nimSum = 0;
        ll a;
        for (ll j = 0; j < heapAmount; j ++){
            cin >> a;
            nimSum = nimSum ^ a;
        }
        if (nimSum == 0){
            cout << "second\n";
        }
        else {
            cout << "first\n";
        }
    }

    return 0;
}
