//https://cses.fi/problemset/task/1674

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int recurse(const vector<vector<int>>& workers, vector<int>& subs, int onWorker){
    if (subs[onWorker] >= 0){
        return subs[onWorker];
    }
    int subSum = 0;
    for (int i = 0; i < workers[onWorker].size(); i ++){
        subSum += recurse(workers,subs,workers[onWorker][i]);
    }
    subs[onWorker] = subSum;
    return subSum+1;
}

int main(){
    ios::sync_with_stdio(0);

    int amount;
    cin >> amount;

    vector<vector<int>> workers(amount+1);
    vector<int> subs(amount+1,-1);

    int boss;
    for (int i = 2; i <= amount; i ++){
        cin >> boss;
        workers[boss].push_back(i);
    }

    recurse(workers,subs,1);

    for (int i = 1; i <= amount; i ++){
        cout << subs[i] << " ";
    }
    cout << "\n";



    return 0;
}
