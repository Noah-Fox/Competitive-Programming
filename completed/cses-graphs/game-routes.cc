//https://cses.fi/problemset/task/1681

/**
 * Goal is to determine the number of paths from the first to last node
 *
 * For each node, store the number of paths from that node to the last node - initially zero for all, 1 for the last node
 *
 * In reverse order of topological sorting, set each node's value to the sum of its childrens' values
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD_MAX = 1000000007;

void topoSort(vector<vector<ll>>& graph, vector<ll>& pathAmounts, vector<bool>& processed, ll onNode){
    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        if (!processed[*it]){
            topoSort(graph,pathAmounts,processed,*it);
        }
    }
    processed[onNode] = true;
    if (onNode == graph.size()-1){
        pathAmounts[onNode] = 1;
    }
    else {
        for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
            pathAmounts[onNode] += pathAmounts[*it];
            pathAmounts[onNode] = pathAmounts[onNode] % MOD_MAX;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<vector<ll>> graph(nodeAmount+1);
    ll a, b;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
    }

    //solve
    vector<ll> pathAmounts(nodeAmount+1,0);
    vector<bool> processed(nodeAmount+1,false);
    topoSort(graph,pathAmounts,processed,1);

    cout << pathAmounts[1] << "\n";

    return 0;
}
