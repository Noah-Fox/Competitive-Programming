//https://cses.fi/problemset/task/1131

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int recurse(const vector<vector<int>>& nodes, vector<int>& subs, int onNode){
    if (subs[onNode] >= 0){
        return subs[onNode];
    }
    int subSum = 0;
    for (int i = 0; i < nodes[onNode].size(); i ++){
        subSum += recurse(nodes,subs,nodes[onNode][i]);
    }
    subs[onNode] = subSum;
    return subSum+1;
}

int main(){
    ios::sync_with_stdio(0);

    int amount;
    cin >> amount;

    vector<vector<int>> nodes(amount+1);
    vector<int> subs(amount+1,-1);

    int boss;
    for (int i = 2; i <= amount; i ++){
        cin >> boss;
        nodes[boss].push_back(i);
    }

    recurse(nodes,subs,1);

    for (int i = 1; i <= amount; i ++){
        cout << subs[i] << " ";
    }
    cout << "\n";



    return 0;
}
