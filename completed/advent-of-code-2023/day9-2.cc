//Advent of code day 9 puzzle 2

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    string inLine;
    ll sum = 0;
    while (getline(cin,inLine)){
        stringstream ss(inLine);
        vector<ll> nums(istream_iterator<ll>(ss),{});
        
        vector<vector<ll>> sequences;
        bool allZeros = false;
        while (!allZeros){
            vector<ll> nextNums;
            allZeros = true;
            for (size_t i = 0; i < nums.size()-1; i ++){
                ll valDiff = nums[i+1]-nums[i];
                if (valDiff != 0){
                    allZeros = false;
                }
                nextNums.push_back(valDiff);
            }
            sequences.push_back(nums);
            nums = nextNums;
        }


        ll addVal = 0;
        for (ll i = sequences.size()-1; i >= 0; i --){
            addVal = sequences[i][0]-addVal;
        }
        
        sum += addVal;
    }

    cout << sum << "\n";

    return 0;
}
