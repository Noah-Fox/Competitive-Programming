//https://cses.fi/problemset/task/1637

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int startNum;
    cin >> startNum;

    vector<int> nums(startNum+1,0);
    nums[startNum] = 1;

    for (int i = startNum; i > 0; i --){
        if (nums[i] > 0){
            int onDigit = i;
            while (onDigit > 0){
                int toValue = i - (onDigit - (onDigit/10)*10);
                if (toValue >= 0 && (nums[toValue] == 0 || nums[toValue] > nums[i]+1)){
                    nums[toValue] = nums[i]+1;
                }
                onDigit /= 10;
            }
        }
    }

    if (nums[0] == 0){
        cout << "-1\n";
    }else {
        cout << nums[0]-1 << "\n";
    }

    return 0;
}
