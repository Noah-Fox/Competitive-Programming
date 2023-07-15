//https://cses.fi/problemset/task/1680

/**
 * longest path in a directed acyclic graph
 *
 * Construct a topological sorting of the graph. 
 *
 * For every node u, in order of the sorting: For every edge (u,v): if distance[u]+1 > distance[v]: distance[v] = distance[u]+1
*/

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void topoSort(vector<vector<ll>>& graph, stack<ll>& sorted, ll onNode, vector<ll>& states){
    if (states[onNode] == 2) return;
    states[onNode] = 1;
    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        topoSort(graph,sorted,*it,states);
    }
    states[onNode] = 2;
    sorted.push(onNode);
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

    //get topological sorting of graph
    vector<ll> states(nodeAmount+1,0);
    stack<ll> sorted;
    topoSort(graph, sorted, 1, states);
    
    //solve
    vector<ll> dist(nodeAmount+1,0);
    vector<ll> fromNode(nodeAmount+1,0);
    dist[1] = 1;
    while (!sorted.empty()){
        ll onNode = sorted.top();
        sorted.pop();
        for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
            if (dist[onNode] + 1 > dist[*it]){
                dist[*it] = dist[onNode]+1;
                fromNode[*it] = onNode;
            }
        }
    }

    //output solution
    if (dist[nodeAmount] == 0){
        cout << "IMPOSSIBLE\n";
    }
    else {
        stack<ll> path;
        path.push(nodeAmount);
        while (fromNode[path.top()] != 0){
            path.push(fromNode[path.top()]);
        }
        cout << dist[nodeAmount] << "\n";
        while (!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << "\n";
    }

    return 0;
}
