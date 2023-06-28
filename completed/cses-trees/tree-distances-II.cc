//https://cses.fi/problemset/task/1133

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    //the number of descendants of a node
    ll descendants = 0;

    //the sum of distances from the node to every node reached through one of its children
    ll childDistSum = 0;

    //the sum of distances from the node to every node reached through its parent
    ll parentDistSum = 0;

    //the children of the node
    vector<ll> children;
};

//convert a graph to a tree
void makeTree(vector<vector<ll>>& graph, vector<Node>& tree, ll onNode, ll fromNode){
    for (size_t i = 0; i < graph[onNode].size(); i ++){
        if (graph[onNode][i] != fromNode){
            tree[onNode].children.push_back(graph[onNode][i]);
            makeTree(graph,tree,graph[onNode][i],onNode);
        }
    }
}

/**
 * the descendants and childDistSum values of a node are functions of the values of its children
 *
 * recurse down and propogate the values up
*/
void recurseUp(vector<Node>& tree, ll onNode){
    for (size_t i = 0; i < tree[onNode].children.size(); i ++){
        ll toChild = tree[onNode].children[i];
        recurseUp(tree, toChild);
        tree[onNode].descendants += tree[toChild].descendants + 1;
        tree[onNode].childDistSum += tree[toChild].childDistSum;
    }
    tree[onNode].childDistSum += tree[onNode].descendants;
}

/**
 * the parentDistSum value of a node is a function of the values of its parent
 *
 * recurse and propogate down
 *
 * when the current node is reached, its parent node has all values determine
 * 
 * the parentDistSum value is the sum of the parent's parentDistSum and its childDistSum's through its 
 * children other than the current node, plus the number of nodes that are not descendants of the current
 * node
*/
void recurseDown(vector<Node>& tree, ll onNode, ll parentNode, ll nodeAmount){
    tree[onNode].parentDistSum = tree[parentNode].parentDistSum + tree[parentNode].childDistSum;
    if (parentNode != 0){
        tree[onNode].parentDistSum -= tree[onNode].childDistSum + tree[onNode].descendants + 1;
    }
    tree[onNode].parentDistSum += nodeAmount - tree[onNode].descendants - 1;

    for (size_t i = 0; i < tree[onNode].children.size(); i ++){
        recurseDown(tree, tree[onNode].children[i], onNode, nodeAmount);
    }
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
    recurseUp(tree, 1);
    recurseDown(tree, 1, 0, nodeAmount);

    for (ll i = 1; i <= nodeAmount; i ++){
        cout << tree[i].childDistSum + tree[i].parentDistSum << "\n";
    }

    return 0;
}
