//https://cses.fi/problemset/task/1098

/**
 * A game is in a losing state iff the xor sum of the number of sticks in each heap is divisible by 4
*/

// #include <iostream>
#include <bits/stdc++.h>

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
        if (nimSum % 4 == 0){
            cout << "second\n";
        }
        else {
            cout << "first\n";
        }
    }

    return 0;
}
