//https://open.kattis.com/problems/alexandbarb

/*
 * Game theory problem: given n cards, each player can remove between x and y cards
 *
 * Win/lose cases can be propogated from 0 to n: for each lose case i, every case from i+x to i+y is a win case
 *
 * Win/lose cases follow a pattern of x lose cases followed by y win cases. Therefore, a case i is a win case if
 * i % (x+y) >= x
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll cardAmount, minMove, maxMove;
    cin >> cardAmount >> minMove >> maxMove;

    if (cardAmount % (minMove + maxMove) > minMove){
        cout << "Alex\n";
    }
    else {
        cout << "Barb\n";
    }

    return 0;
}
