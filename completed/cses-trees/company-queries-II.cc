//https://cses.fi/problemset/task/1688

/**
 * To solve this, create an array where each element holds the id and depth of a node.
 * Perform depth-first search on the tree. Every time you traverse a node (before, between, and after traversing to each of
 * its children), add that node to the list.
 * The lowest common ancestor of two nodes is the element in the list between the two nodes that has the lowest depth.
 * This can then be solved like a range query using a segment tree.
 */

// #include <iostream>
// #include <vector>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<ll> children;
    ll arrLocation;
};

void createSegmentTree(vector<pair<ll,ll>>& segmentTree, vector<Node>& tree, ll onNode, ll& onElement, ll depth){
    segmentTree[onElement] = {depth, onNode};
    tree[onNode].arrLocation = onElement;
    onElement ++;
    for (auto it = tree[onNode].children.begin(); it != tree[onNode].children.end(); it ++){
        createSegmentTree(segmentTree,tree,*it,onElement,depth+1);
        segmentTree[onElement] = {depth, onNode};
        onElement ++;
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, queryAmount;
    cin >> nodeAmount >> queryAmount;

    //input tree
    vector<Node> tree(nodeAmount+1);
    ll a, b;
    for (ll i = 2; i <= nodeAmount; i ++){
        cin >> a;
        tree[a].children.push_back(i);
    }

    //create traversal array
    ll elementAmount = 2*nodeAmount-1;

    //set to power of two
    if (__builtin_popcount(elementAmount) > 1){
        ll logVal = log2(elementAmount)+1;
        elementAmount = pow(2,logVal);
    }

    vector<pair<ll,ll>> segmentTree(2*elementAmount,{2000000,0});//store {depth, node id}

    ll passElementAmount = elementAmount;
    createSegmentTree(segmentTree,tree,1,passElementAmount,0);

    //create segment tree
    for (ll i = elementAmount-1; i >= 0; i --){
        if (segmentTree[2*i].first < segmentTree[2*i+1].first){
            segmentTree[i] = segmentTree[2*i];
        }
        else {
            segmentTree[i] = segmentTree[2*i+1];
        }
    }

    //solve queries
    for (ll i = 0; i < queryAmount; i ++){
        cin >> a >> b;
        a = tree[a].arrLocation;
        b = tree[b].arrLocation;
        if (a > b){
            swap(a,b);
        }
        pair<ll,ll> m = {2000000,0};
        while (a <= b){
            if (a % 2 == 1){
                if (segmentTree[a].first < m.first){
                    m = segmentTree[a];
                }
                a ++;
            }
            if (b % 2 == 0){
                if (segmentTree[b].first < m.first){
                    m = segmentTree[b];
                }
                b --;
            }
            a /= 2;
            b /= 2;
        }
        cout << m.second << "\n";
    }

    return 0;
}
