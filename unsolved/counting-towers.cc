//https://cses.fi/problemset/task/2413

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    int testAmount;
    cin >> testAmount;

    ll maxTest = 0;
    vector<ll> testCases(testAmount);
    for (int i = 0; i < testAmount; i ++){
        cin >> testCases[i];
        if (testCases[i] > maxTest){
            maxTest = testCases[i];
        }
    }

    vector<ll> arr(maxTest+1);
    

    return 0;
}
