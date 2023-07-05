//https://cses.fi/problemset/task/1687

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<vector<ll>>& children, vector<vector<pair<ll,ll>>>& queryNodes, vector<ll>& querySolutions, ll onNode, vector<ll> parentArr){
    for (size_t i = 0; i < queryNodes[onNode].size(); i ++){
        if (queryNodes[onNode][i].first <= parentArr.size()){
            querySolutions[queryNodes[onNode][i].second] = parentArr[parentArr.size()-queryNodes[onNode][i].first];
        }
    }
    parentArr.push_back(onNode);
    for (size_t i = 0; i < children[onNode].size(); i ++){
        solve(children,queryNodes,querySolutions,children[onNode][i],parentArr);
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, queryAmount;
    cin >> nodeAmount >> queryAmount;

    //input tree
    vector<vector<ll>> children(nodeAmount+1);
    ll a, b;
    for (ll i = 2; i <= nodeAmount; i ++){
        cin >> a;
        children[a].push_back(i);
    }

    //store a list of pairs for the query at each node
    //pairs store {generations up to query, query id}
    vector<vector<pair<ll,ll>>> queryNodes(nodeAmount+1);
    vector<ll> querySolutions(queryAmount,-1);
    for (ll i = 0; i < queryAmount; i ++){
        cin >> a >> b;
        queryNodes[a].push_back({b,i});
    }

    //solve
    solve(children,queryNodes,querySolutions,1,{});

    for (ll i = 0; i < queryAmount; i ++){
        cout << querySolutions[i] << "\n";
    }

    return 0;
}
