//https://open.kattis.com/problems/thanosthehero

/*
 * Given a list of integers, find the sum of amounts you have to decrease each number to make it strictly increasing
 *
 * Iterate backwards through the list. Decrease each number to make it 1 less than the following.
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll worldAmount;
    cin >> worldAmount;

    //input every number to a vector
    vector<ll> worlds(worldAmount);
    for (ll i = 0; i < worldAmount; i ++){
        cin >> worlds[i];
    }

    //go backward through worlds
    ll killAmount = 0;
    ll prevPop = worlds[worldAmount-1];
    for (ll i = worldAmount-2; i >= 0; i --){
        if (worlds[i] >= prevPop){
            killAmount += worlds[i] - prevPop + 1;
            prevPop --;
        }
        else {
            prevPop = worlds[i];
        }
    }

    if (prevPop < 0){
        cout << "1\n";
    }
    else {
        cout << killAmount << "\n";
    }

    return 0;
}
