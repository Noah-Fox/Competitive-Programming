//https://cses.fi/problemset/task/1646

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pre(ll val){
    return val & (-val);
}

int main(){
    ios::sync_with_stdio(0);

    //input first line
    int numAmount, queryAmount;
    cin >> numAmount >> queryAmount;

    //input second line
    vector<ll> nums(numAmount+1);
    for (int i = 1; i <= numAmount; i ++){
        cin >> nums[i];
    }

    //create tree
    vector<ll> tree(numAmount+1);
    for (int i = 1; i <= numAmount; i ++){
        ll sum = 0;
        for (int x = i+1-pre(i); x <= i; x ++){
            sum += nums[x];
        }
        tree[i] = sum;
    }

    //find range queries
    int a, b;
    for (int q = 0; q < queryAmount; q ++){
        cin >> a >> b;
        a --;
        ll aSum = 0;
        ll bSum = 0;

        for (int k = a; k >= 1; k -= pre(k)){
            aSum += tree[k];
        }
        for (int k = b; k >= 1; k -= pre(k)){
            bSum += tree[k];
        }

        cout << bSum-aSum << "\n";
    }

    return 0;
}
