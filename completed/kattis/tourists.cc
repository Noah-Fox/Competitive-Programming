//https://open.kattis.com/problems/tourists

/*
 * Given a tree of nodes numbered 1 to n, find the sum of distances between all pairs of nodes a and b, where b > a 
 * and b is a multiple of a
 *
 * Utilize a tree query lowest common ancestors algorithm
 *
 * Create a list of {node,depth}, inserting a node every time it is traversed during depth-first search (before, between,
 * and after traversing to its children). Make a segment tree out of this list, finding the minimum depth of each. The 
 * lowest common ancestor of nodes a and b is the node with the minimum depth between them in the list. Use this to find
 * the distance between them
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void depthFirst(vector<vector<ll>>& tree, vector<pair<ll,ll>>& iterList, ll& iterListIndex, vector<ll>& iterListPos, ll onNode, ll depth, ll fromNode, vector<ll>& nodeDepths){
    nodeDepths[onNode] = depth;
    iterList[iterListIndex] = {onNode,depth};
    iterListPos[onNode] = iterListIndex;
    iterListIndex ++;
    for (auto it = tree[onNode].begin(); it != tree[onNode].end(); it ++){
        if (*it != fromNode){
            depthFirst(tree,iterList,iterListIndex,iterListPos,*it,depth+1,onNode,nodeDepths);
            iterList[iterListIndex] = {onNode,depth};
            iterListIndex ++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll nodeAmount;
    cin >> nodeAmount;

    //input as an adjacency list
    vector<vector<ll>> tree(nodeAmount+1);
    ll a, b;
    for (ll i = 0; i < nodeAmount-1; i ++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    //find the necessary size of the tree array for it to be a power of two
    ll iterListSize = nodeAmount*2-1;
    if (__builtin_popcount(iterListSize) > 1){
        ll logVal = log2(iterListSize)+1;
        iterListSize = pow(2,logVal);
    }

    //depth-first search, recording a node every time you iterate over it
    vector<pair<ll,ll>> iterList(2*iterListSize,{0,1000000007});//stores {node id, depth}
    vector<ll> iterListPos(nodeAmount+1,-1);//for each node, its first position in iterList
    vector<ll> nodeDepths(nodeAmount+1);//depth of each node
    ll iterListIndex = iterListSize;
    depthFirst(tree, iterList, iterListIndex, iterListPos, 1, 1, 0, nodeDepths);

    //create the segment tree
    for (ll i = iterListSize-1; i > 0; i --){
        if (iterList[i*2].second < iterList[i*2+1].second){
            iterList[i] = iterList[i*2];
        }
        else {
            iterList[i] = iterList[i*2+1];
        }
    }

    //process every valid pair of nodes
    ll sum = 0;
    for (ll i = 1; i <= nodeAmount/2; i ++){
        for (ll x = 2*i; x <= nodeAmount; x += i){
            //process range query for nodes i and x
            ll a = iterListPos[i];
            ll b = iterListPos[x];
            if (b < a) swap(a,b);

            pair<ll,ll> minVal = {0,1000000007};
            while (a <= b){
                if (a % 2 == 1){
                    if (iterList[a].second < minVal.second) minVal = iterList[a];
                    a ++;
                }
                if (b % 2 == 0){
                    if (iterList[b].second < minVal.second) minVal = iterList[b];
                    b --;
                }
                a /= 2;
                b /= 2;
            }
            //find distance between two nodes and add it to the sum
            sum += 1 + nodeDepths[i] - minVal.second;
            sum += nodeDepths[x] - minVal.second;
        }
    }

    cout << sum << "\n";

    return 0;
}
