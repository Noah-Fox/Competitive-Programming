//https://open.kattis.com/problems/whostheboss

/*
 * Goal is to construct a tree, and determine for each node its parent and the number of descendants it has
 *
 * Each node has two values: n.height and n.salary
 *
 * To find the parent p of a node n, sort the nodes by salary, then take the first node after n whose height is greater
 *  than or equal to n.height
*/

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,pair<ll,ll>> worker;
#define salary first
#define height second.first
#define id second.second 

struct Node{
    ll idVal;
    ll parent = 0;
    vector<ll> children;
    ll subAmount = 0;
};

ll countSubs(vector<Node>& tree, ll onNode){
    for (auto it = tree[onNode].children.begin(); it != tree[onNode].children.end(); it ++){
        tree[onNode].subAmount += 1 + countSubs(tree,*it);
    }
    return tree[onNode].subAmount;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll workerAmount, queryAmount;
    cin >> workerAmount >> queryAmount;

    //input workers
    vector<worker> workers(workerAmount);
    vector<Node> workerTree(workerAmount);
    map<ll,ll> idToIndex;
    for (ll i = 0; i < workerAmount; i ++){
        cin >> workers[i].id >> workers[i].salary >> workers[i].height;
        idToIndex[workers[i].id] = i;
        workerTree[i].idVal = workers[i].id;
    }

    sort(workers.begin(),workers.end());

    //figure out the parent of each node
    priority_queue<pair<ll,ll>> workerQ;//store {-height,id}
    for (ll i = 0; i < workerAmount; i ++){
        while (!workerQ.empty() && -workerQ.top().first <= workers[i].height){
            workerTree[idToIndex[workers[i].id]].children.push_back(idToIndex[workerQ.top().second]);
            workerTree[idToIndex[workerQ.top().second]].parent = workers[i].id;
            workerQ.pop();
        }
        workerQ.push({-workers[i].height,workers[i].id});
    }

    //find the number of descendants of each node
    countSubs(workerTree,idToIndex[workers[workerAmount-1].id]);

    //process queries and output
    ll q;
    for (ll i = 0; i < queryAmount; i ++){
        cin >> q;
        cout << workerTree[idToIndex[q]].parent << " " << workerTree[idToIndex[q]].subAmount << "\n";
    }


    return 0;
}
