//https://open.kattis.com/problems/integerdivision

/**
 * Given a set of numbers and a divisor, find the amount of pairs of numbers that are equal to the same number when
 * integer divided by the divisor
 *
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ll numAmount, divisor;
    cin >> numAmount >> divisor;

    //input and sort all numbers
    vector<ll> nums(numAmount);
    for (ll i = 0; i < numAmount; i ++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());

    //iterate through all numbers
    ll pairSum = 0;
    ll currentAmount = 0;
    ll prevGroup = 0;
    for (auto it = nums.begin(); it != nums.end(); it ++){
        ll currentGroup = *it / divisor;
        if (currentGroup != prevGroup){
            prevGroup = currentGroup;
            pairSum += currentAmount * (currentAmount-1) / 2;
            currentAmount = 1;
        }
        else {
            currentAmount ++;
        }
    }

    pairSum += currentAmount * (currentAmount-1) / 2;

    cout << pairSum << "\n";

    return 0;
}
