//https://cses.fi/problemset/task/1652

// #include <iostream>
// #include <vector>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll processRow(const vll& row, const ll& forestSize, ll x1, ll x2){
    x1 += forestSize-1;
    x2 += forestSize-1;
    ll sum = 0;

    while (x1 <= x2){
        if (x1 % 2 == 1){
            sum += row[x1];
            x1 ++;
        }
        if (x2 % 2 == 0){
            sum += row[x2];
            x2 --;
        }
        x1 /= 2;
        x2 /= 2;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);

    ll realForestSize, forestSize, queryAmount;
    cin >> realForestSize >> queryAmount;

    //set forestSize to a power of 2
    forestSize = realForestSize;
    if (__builtin_popcount(forestSize) > 1){
        ll logVal = log2(forestSize)+1;
        forestSize = pow(2,logVal);
    }

    vvll forest(2*forestSize, vll(2*forestSize,0));

    //input forest
    cin.ignore();
    for (ll row = 0; row < realForestSize; row ++){
        for (ll col = 0; col < realForestSize; col ++){
            if (cin.peek() == '*'){
                forest[forestSize+row][forestSize+col] = 1;
            }
            cin.ignore();
        }
        cin.ignore();
    }

    //create 2D segment tree
    for (ll row = 2*forestSize-1; row >= forestSize; row --){
        for (ll col = forestSize-1; col > 0; col --){
            forest[row][col] = forest[row][col*2] + forest[row][col*2+1];
        }
    }
    for (ll row = forestSize-1; row > 0; row --){
        for (ll col = 2*forestSize-1; col > 0; col --){
            forest[row][col] = forest[2*row][col] + forest[2*row+1][col];
        }
    }

    for (ll i = 0; i < queryAmount; i ++){
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        ll sum = 0;
        y1 += forestSize-1;
        y2 += forestSize-1;

        while (y1 <= y2){
            if (y1 % 2 == 1){
                sum += processRow(forest[y1],forestSize,x1,x2);
                y1 ++;
            }
            if (y2 % 2 == 0){
                sum += processRow(forest[y2],forestSize,x1,x2);
                y2 --;
            }
            y1 /= 2;
            y2 /= 2;
        }
        cout << sum << " ";
    }
    cout << "\n";

    return 0;
}
