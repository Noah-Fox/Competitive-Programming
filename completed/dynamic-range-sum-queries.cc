//https://cses.fi/problemset/task/1648

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
        nums[i] = nums[2*i] + nums[2*i+1];
    }

    

    //input and solve queries
    int a, b, queryType;
    ll u;
    for (int q = 0; q < queryAmount; q ++){
        cin >> queryType;
        if (queryType == 1){
            cin >> a >> u;
            a += numAmount-1;
            ll changeBy = u-nums[a];
            while (a >= 1){
                nums[a] += changeBy;
                a /= 2;
            }
        }
        else{
            cin >> a >> b;
            a += numAmount-1;
            b += numAmount-1;
            ll sum = 0;
            while (a <= b){
                if (a%2 == 1) sum += nums[a++];
                if (b%2 == 0) sum += nums[b--];
                a /= 2;
                b /= 2;
            }
            cout << sum << "\n";
        }
    }

    return 0;
}
