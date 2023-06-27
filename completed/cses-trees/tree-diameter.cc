//https://cses.fi/problemset/task/1131

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void searchTree(const vector<vector<ll>>& tree, ll nodeOn, ll nodeFrom, ll dist, ll& furthestDist, ll& furthestNode){
    ll getFurthest = nodeOn;
    ll getDist = dist;
    for (size_t i = 0; i < tree[nodeOn].size(); i ++){
        if (tree[nodeOn][i] != nodeFrom){
            searchTree(tree, tree[nodeOn][i], nodeOn, dist+1, getDist, getFurthest);

            if (getDist > furthestDist){
                furthestDist = getDist;
                furthestNode = getFurthest;
            }
        }
    }
    if (getDist > furthestDist){
        furthestDist = getDist;
        furthestNode = getFurthest;
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount;
    cin >> nodeAmount;

    if (nodeAmount == 0){
        cout << "0\n";
        return 0;
    }

    vector<vector<ll>> tree(nodeAmount+1);

    ll a, b;
    for (int i = 1; i < nodeAmount; i ++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    ll furthestDist = 0;
    ll furthestNode = 1;

    searchTree(tree, 1, 0, 0, furthestDist, furthestNode);
    furthestDist = 0;
    searchTree(tree, furthestNode, 0, 0, furthestDist, furthestNode);

    cout << furthestDist << "\n";

    return 0;
}
