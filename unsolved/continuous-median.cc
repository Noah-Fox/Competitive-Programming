//https://open.kattis.com/problems/continuousmedian

#include <iostream>
#include <vector>

using namespace std;

void orderedInsert(vector<int>& v, int num){
    if (v.size() == 0){
        v.push_back(num);
        return;
    }
    v.insert(upper_bound(v.begin(),v.end(),num),num);
}

int main(){

    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i ++){
        int numAmount;
        cin >> numAmount;
        
        vector<int> nums;
        int sum = 0;
        int in;
        for (int x = 0; x < numAmount; x ++){
            cin >> in;
            orderedInsert(nums,in);
            if (x % 2 == 0){
                sum += nums[x/2];
            }
            else {
                sum += 0.5*(nums[(x-1)/2] + nums[(x+1)/2]);
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
