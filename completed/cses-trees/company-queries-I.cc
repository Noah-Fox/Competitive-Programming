//https://cses.fi/problemset/task/1687

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<ll> children;
    vector<pair<ll,ll>> queries;//{levels up, query id}
};

void solve(vector<Node>& tree, vector<ll>& querySolutions, vector<ll>& path, ll onNode, ll onLevel){
    for (auto it = tree[onNode].queries.begin(); it != tree[onNode].queries.end(); it ++){
        if (it -> first <= onLevel){
            querySolutions[it -> second] = path[onLevel - (it -> first)];
        }
    }
    path[onLevel] = onNode;
    for (auto it = tree[onNode].children.begin(); it != tree[onNode].children.end(); it ++){
        solve(tree, querySolutions, path, *it, onLevel+1);
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, queryAmount;
    cin >> nodeAmount >> queryAmount;

    //input and create tree
    vector<Node> tree(nodeAmount+1);
    ll a, b;
    for (ll i = 2; i <= nodeAmount; i ++){
        cin >> a;
        tree[a].children.push_back(i);
    }

    //input queries
    for (ll i = 1; i <= queryAmount; i ++){
        cin >> a >> b;
        tree[a].queries.push_back({b,i});
    }

    vector<ll> querySolutions(queryAmount+1,-1);
    vector<ll> path(nodeAmount,-1);

    //solve
    solve(tree,querySolutions,path,1,0);

    //output solution
    for (ll i = 1; i <= queryAmount; i ++){
        cout << querySolutions[i] << " ";
    }
    cout << "\n";

    return 0;
}
