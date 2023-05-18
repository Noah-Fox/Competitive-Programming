//https://cses.fi/problemset/task/1651

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    //input first line
    int numAmount, queryAmount;
    cin >> numAmount >> queryAmount;

    //input second line
    vector<ll> data(numAmount);
    for (int i = 0; i < numAmount; i ++){
        cin >> data[i];
    }

    //make difference array
    vector<ll> nums(2*numAmount);
    nums[numAmount] = data[0];
    for (int i = 1; i < numAmount; i ++){
        nums[i+numAmount] = data[i] - data[i-1];
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
        //range update
        if (queryType == 1){
            cin >> a >> b >> u;
            a += numAmount-1;
            b += numAmount-1;
            while (a >= 1){
                nums[a] += u;
                a /= 2;
            }
            while (b >= 1){
                nums[b] -= u;
                b /= 2;
            }
        }
        //element query
        else{
            cin >> b;
            a = 1;
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
