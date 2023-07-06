//https://cses.fi/problemset/task/1135

/**
 * Same procedure as the company-queries-II problem, except you first need to convert from graph to tree, and at the 
 * end you need to find the distances between the depth of the common ancestor to the two nodes
*/

// #include <iostream>
// #include <vector>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<ll> children;
    ll depth;
    ll arrLocation;
};

void rootTree(vector<vector<ll>>& graph, vector<Node>& tree, ll onNode, ll fromNode){
    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        if (*it != fromNode){
            tree[onNode].children.push_back(*it);
            rootTree(graph,tree,*it,onNode);
        }
    }
}

void createSegmentTree(vector<pair<ll,ll>>& segmentTree, vector<Node>& tree, ll onNode, ll& onElement, ll depth){
    tree[onNode].depth = depth;
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

    //input graph
    vector<vector<ll>> graph(nodeAmount+1);
    ll a, b;
    for (ll i = 1; i < nodeAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //convert to tree
    vector<Node> tree(nodeAmount+1);
    rootTree(graph,tree,1,0);

    //create traversal array
    ll elementAmount = 2*nodeAmount-1;
    if (__builtin_popcount(elementAmount) > 1){
        //set to power of two
        ll logVal = log2(elementAmount)+1;
        elementAmount = pow(2,logVal);
    }
    vector<pair<ll,ll>> segmentTree(2*elementAmount,{2000000,0});//stores {depth, node id}
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
    ll startA, startB;
    for (ll i = 0; i < queryAmount; i ++){
        cin >> startA >> startB;
        a = tree[startA].arrLocation;
        b = tree[startB].arrLocation;
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
        cout << (tree[startA].depth-m.first) + (tree[startB].depth-m.first) << "\n";
    }

    return 0;
}
