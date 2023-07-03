//https://cses.fi/problemset/task/1687

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<vector<ll>>& children, vector<vector<pair<ll,ll>>>& queryNodes, vector<ll>& querySolutions, ll onNode){
    for (size_t i = 0; i < children[onNode].size(); i ++){
        ll toChild = children[onNode][i];
        solve(children,queryNodes,querySolutions,toChild);
        for (size_t x = 0; x < queryNodes[toChild].size(); x ++){
            if (queryNodes[toChild][x].first == 1){
                querySolutions[queryNodes[toChild][x].second] = onNode;
            }
            else {
                queryNodes[onNode].push_back({queryNodes[toChild][x].first-1,queryNodes[toChild][x].second});
            }
        }
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
    solve(children,queryNodes,querySolutions,1);

    for (ll i = 0; i < queryAmount; i ++){
        cout << querySolutions[i] << "\n";
    }

    return 0;
}
