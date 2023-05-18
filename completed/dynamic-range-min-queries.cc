//https://cses.fi/problemset/task/1649

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll min(ll val1, ll val2){
    if (val1 <= val2) return val1;
    return val2;
}

int main(){
    ios::sync_with_stdio(0);

    //input first line
    int numAmount, queryAmount;
    cin >> numAmount >> queryAmount;

    //input second line
    vector<ll> nums(2*numAmount);
    for (int i = 0; i < numAmount; i ++){
        cin >> nums[i+numAmount];
    }

    //fill in tree
    for (int i = numAmount-1; i > 0; i --){
        nums[i] = min(nums[2*i],nums[2*i+1]);
    }

    

    //input and solve queries
    int a, b, queryType;
    ll u;
    for (int q = 0; q < queryAmount; q ++){
        cin >> queryType;
        //update tree
        if (queryType == 1){
            cin >> a >> u;
            a += numAmount-1;
            nums[a] = u;
            a /= 2;
            while (a >= 1){
                nums[a] = min(nums[2*a],nums[2*a+1]);
                a /= 2;
            }
        }
        //find query
        else{
            cin >> a >> b;
            a += numAmount-1;
            b += numAmount-1;
            ll gotMin = 10000000000;
            while (a <= b){
                if (a%2 == 1) gotMin = min(gotMin,nums[a++]);
                if (b%2 == 0) gotMin = min(gotMin,nums[b--]);
                a /= 2;
                b /= 2;
            }
            cout << gotMin << "\n";
        }
    }

    return 0;
}
