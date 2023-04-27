//https://cses.fi/problemset/task/1090

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    int childAmount, maxWeight;

    cin >> childAmount >> maxWeight;

    vector<int> childWeights (childAmount);

    for (int i = 0; i < childAmount; i ++){
        cin >> childWeights[i];
    }

    sort(childWeights.begin(),childWeights.end());

    int count = 0;
    int onMax = childAmount - 1;
    int onMin = 0;

    while (onMin <= onMax){
        count ++;
        if (childWeights[onMax] + childWeights[onMin] > maxWeight){
            onMax --;
        }
        else {
            onMax --;
            onMin ++;
        }
    }
    cout << count << "\n";

    return 0;
}
