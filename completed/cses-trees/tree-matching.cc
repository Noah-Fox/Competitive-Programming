//https://cses.fi/problemset/task/1130

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * Every subtree has two values: the maximum number of pairs inside it if its root has 
 * a pair above it (previousVal), and the maximum number of pairs inside it if its root
 * does not have a pair above it (noPreviousVal)
 * 
 * For a leaf node, both of these values are zero
 * 
 * For a parent node i:
 *      i.previousVal = sum(i.children[x].noPreviousVal)
 *          - since i is already connected to a pair in this case, it will have no pairs below it, and each of its
 *          children's subtrees will have the noPreviousVal amount of pairs
 *      i.noPreviousVal = 1 + sum(i.children[x].noPreviousVal) + max(i.children[x].previousVal-i.children[x].noPreviousVal)
 *          - in this case, i will have one pair below it. This equation finds the optimal child to connect the pair to
 *          - the equation is essentially: 1 + maxChild.previousVal + sum(minChildren[x].noPreviousVal)
*/
struct Node{
    ll noPreviousVal = 0;
    ll previousVal = 0;
    vector<ll> children;
};

void makeTree(vector<vector<ll>>& graph, vector<Node>& tree, ll onNode, ll fromNode){
    for (size_t i = 0; i < graph[onNode].size(); i ++){
        if (graph[onNode][i] != fromNode){
            tree[onNode].children.push_back(graph[onNode][i]);
            makeTree(graph,tree,graph[onNode][i],onNode);
        }
    }
}

void recurseSolve(vector<Node>& tree, ll onNode){
    if (tree[onNode].children.size() == 0){
        return;
    }
    tree[onNode].noPreviousVal = 1;
    ll maxDiff = -200000;//max(i.previousVal-i.noPreviousVal)
    for (size_t i = 0; i < tree[onNode].children.size(); i ++){
        ll toChild = tree[onNode].children[i];
        recurseSolve(tree,toChild);
        tree[onNode].previousVal += tree[toChild].noPreviousVal;
        tree[onNode].noPreviousVal += tree[toChild].noPreviousVal;
        if (tree[toChild].previousVal-tree[toChild].noPreviousVal > maxDiff){
            maxDiff = tree[toChild].previousVal-tree[toChild].noPreviousVal;
        }
    }
    tree[onNode].noPreviousVal += maxDiff;
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount;
    cin >> nodeAmount;

    vector<vector<ll>> graph(nodeAmount+1);

    //input the tree as a graph
    ll a, b;
    for (ll i = 1; i < nodeAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //convert to tree data structure format
    vector<Node> tree(nodeAmount+1);
    makeTree(graph,tree,1,0);

    //solve
    recurseSolve(tree,1);
    cout << tree[1].noPreviousVal << "\n";

    return 0;
}
