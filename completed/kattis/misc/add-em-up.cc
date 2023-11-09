//https://open.kattis.com/problems/addemup

// #include <iostream>
// #include <vector>
// #include <set>
// #include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll numAmount, targetSum;
    cin >> numAmount >> targetSum;

    unordered_set<ll> nums;

    ll onNum, flippedNum, holdNum;

    for (ll i = 0; i < numAmount; i ++){
        cin >> onNum;
        holdNum = onNum;
        bool isValid = true;

        flippedNum = 0;
        while (onNum > 0){
            ll m = onNum % 10;
            if (m == 3 || m == 4 || m == 7){
                isValid = false;
            }
            if (m == 6) flippedNum = flippedNum * 10 + 9;
            else if (m == 9) flippedNum = flippedNum * 10 + 6;
            else flippedNum = flippedNum * 10 + m;
            
            onNum /= 10;
        }

        if (isValid){
            if (nums.count(targetSum - flippedNum)){
                cout << "YES\n";
                return 0;
            }
            if (nums.count(targetSum-holdNum)){
                cout << "YES\n";
                return 0;
            }

            nums.insert(flippedNum);
            nums.insert(holdNum);
        }
        else {
            if (nums.count(targetSum-holdNum)){
                cout << "YES\n";
                return 0;
            }
            nums.insert(holdNum);
        }
    }

    cout << "NO\n";

    return 0;
}
