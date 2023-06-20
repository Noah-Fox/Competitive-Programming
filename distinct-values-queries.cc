//https://cses.fi/problemset/task/1734

// #include <iostream>
// #include <vector>
// #include <set>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<set<ll>> vsl;

int main(){
    ios::sync_with_stdio(0);

    ll arrSize, realSize, queryAmount;
    cin >> realSize >> queryAmount;

    //set arrSize to a power of 2
    arrSize = realSize;
    if (__builtin_popcount(arrSize) > 1){
        ll logVal = log2(arrSize);
        arrSize = pow(2,logVal+1);
    }

    vsl arr(2*arrSize);

    //input values
    for (ll i = arrSize; i < arrSize+realSize; i ++){
        ll val;
        cin >> val;
        arr[i].insert(val);
    }

    //create tree
    for (ll i = arrSize-1; i > 0; i --){
        arr[i].insert(arr[2*i].begin(),arr[2*i].end());
        arr[i].insert(arr[2*i+1].begin(),arr[2*i+1].end());
    }

    for (ll q = 0; q < queryAmount; q ++){
        ll a, b;
        cin >> a >> b;
        a += arrSize-1;
        b += arrSize-1;

        set<ll> sumSet;

        while (a <= b){
            if (a % 2 == 1){
                sumSet.insert(arr[a].begin(),arr[a].end());
                a ++;
            }
            if (b % 2 == 0){
                sumSet.insert(arr[b].begin(),arr[b].end());
                b --;
            }
            a /= 2;
            b /= 2;
        }
        cout << sumSet.size() << " ";
    }
    cout << "\n";

    return 0;
}
