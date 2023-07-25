//https://cses.fi/problemset/task/1640

/**
 * store each value and its original position in an array. sort the array
 *
 * begin with pointers to the first and last elements. while the first is before the last, move them together
 * to get a sum closer to the target
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll numAmount, target;
    cin >> numAmount >> target;

    //input numbers
    vector<pair<ll,ll>> nums(numAmount);
    for (ll i = 0; i < numAmount; i ++){
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(),nums.end());

    //solve
    ll low = 0;
    ll high = numAmount - 1;
    while (low < high){
        if (nums[low].first + nums[high].first == target){
            cout << nums[low].second+1 << " " << nums[high].second+1 << "\n";
            return 0;
        }
        else if (nums[low].first + nums[high].first < target){
            low ++;
        }
        else {
            high --;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
