//https://cses.fi/problemset/task/1132

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<ll> children;
    ll maxChildDist1 = 0;
    ll maxChildNode1 = 0;
    ll maxChildDist2 = 0;
    ll maxChildNode2 = 0;
    ll maxParentDist = 0;
};

ll recurse(vector<Node>& tree, ll onNode, ll fromNode, ll dist){
    for (size_t i = 0; i < tree[onNode].children.size(); i ++){
        if (tree[onNode].children[i] != fromNode){
            ll childDist = recurse(tree, tree[onNode].children[i], onNode, dist+1) + 1;
            if (childDist > tree[onNode].maxChildDist1){
                tree[onNode].maxChildDist2 = tree[onNode].maxChildDist1;
                tree[onNode].maxChildNode2 = tree[onNode].maxChildNode1;
                tree[onNode].maxChildDist1 = childDist;
                tree[onNode].maxChildNode1 = tree[onNode].children[i];
            }
            else if (childDist > tree[onNode].maxChildDist2){
                tree[onNode].maxChildDist2 = childDist;
                tree[onNode].maxChildNode2 = tree[onNode].children[i];
            }
        }
    }
    return tree[onNode].maxChildDist1;
}

void recurse2(vector<Node>& tree, ll onNode, ll fromNode, ll dist){
    ll parentMaxChild;
    if (tree[fromNode].maxChildNode1 == onNode){
        parentMaxChild = tree[fromNode].maxChildDist2;
    }
    else {
        parentMaxChild = tree[fromNode].maxChildDist1;
    }

    if (fromNode == 0){
        tree[onNode].maxParentDist = parentMaxChild;
    }
    else{
        tree[onNode].maxParentDist = max(parentMaxChild,tree[fromNode].maxParentDist)+1;
    }

    for (ll i = 0; i < tree[onNode].children.size(); i ++){
        if (tree[onNode].children[i] != fromNode){
            recurse2(tree, tree[onNode].children[i], onNode, dist+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount;
    cin >> nodeAmount;

    vector<Node> tree(nodeAmount+1);

    ll a, b;
    for (int i = 1; i < nodeAmount; i ++){
        cin >> a >> b;
        tree[a].children.push_back(b);
        tree[b].children.push_back(a);
    }

    recurse(tree, 1, 0, 0);
    recurse2(tree, 1, 0, 0);

    for (ll i = 1; i <= nodeAmount; i ++){
        cout << max(tree[i].maxChildDist1,tree[i].maxParentDist) << "\n";
    }
    

    return 0;
}
