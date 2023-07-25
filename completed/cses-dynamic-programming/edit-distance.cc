//https://cses.fi/problemset/task/1639

/**
 * given strings a and b, find the minimum number of operations (insert, remove, replace) to convert a into b
 *
 * f(j,i) is the solution considering the first j characters of a and i characters of b
 *
 * there are only four possibilities for f(j,i):
 *      1. j == 0: f(j,i) = i
 *      2. i == 0: f(j,i) = j
 *      3. a[j-1] == b[i-1]: f(j,i) = f(j-1,i-1)
 *      4. else: f(j,i) = 1 + min(f(j-1,i), f(j-1,i-1), f(f,i-1))
 *
 * You can construct a 2d array dp, where dp[j][i] = f(j,i). To save space, you only need the previous row
 * to construct the current row of the array.
*/

// #include <iostream>
// #include <vector>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll min(ll x, ll y, ll z){
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int main(){
    ios::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;

    ll aLen = a.length();
    ll bLen = b.length();

    //solve
    vector<ll> prevRow(aLen+1,0);

    for (ll i = 0; i <= bLen; i ++){
        vector<ll> curRow(aLen+1,0);
        for (ll j = 0; j <= aLen; j ++){
            if (i == 0){
                curRow[j] = j;
            }
            else if (j == 0){
                curRow[j] = i;
            }
            else if (a[j-1] == b[i-1]){
                curRow[j] = prevRow[j-1];
            }
            else {
                curRow[j] = 1 + min(curRow[j-1],prevRow[j-1],prevRow[j]);
            }
        }
        prevRow = curRow;
    }

    cout << prevRow[aLen] << "\n";

    return 0;
}
