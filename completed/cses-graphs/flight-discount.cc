//https://cses.fi/problemset/task/1195

/**
 * Goal of problem is to find shortest path from first to last node, while being able to divide any single edge weight
 * by two.
 *
 * Run dijkstra twice. First from the first node, then from the last node, using reversed edges. Then find the edge going
 * from node a to b such that the distance from the start to a plus the distance from b to the end plus half the weight 
 * of the edge is minimal.
*/

// #include <iostream>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<pair<ll,ll>> edges;//{toNode, weight}
    ll distance = 9000000000000000000;
    bool processed = false;
};

void dijkstra(vector<Node>& graph, ll start){
    graph[start].distance = 0;
    priority_queue<pair<ll,ll>> q;
    q.push({0,start});
    while (!q.empty()){
        ll onNode = q.top().second;
        q.pop();
        if (!graph[onNode].processed){
            graph[onNode].processed = true;
            for (auto edge = graph[onNode].edges.begin(); edge != graph[onNode].edges.end(); edge ++){
                if (graph[onNode].distance + (edge -> second) < graph[edge -> first].distance){
                    graph[edge -> first].distance = graph[onNode].distance + (edge -> second);
                    q.push({-graph[edge -> first].distance,edge -> first});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<Node> forwardGraph(nodeAmount+1);
    vector<Node> reverseGraph(nodeAmount+1);
    ll from, to, weight;
    for (ll i = 1; i <= edgeAmount; i ++){
        cin >> from >> to >> weight;
        forwardGraph[from].edges.push_back({to,weight});
        reverseGraph[to].edges.push_back({from,weight});
    }

    //run dijkstra
    dijkstra(forwardGraph,1);
    dijkstra(reverseGraph,nodeAmount);

    //find the optimal edge
    ll minRoute = 9000000000000000000;
    for (ll i = 1; i <= nodeAmount; i ++){
        for (auto edge = forwardGraph[i].edges.begin(); edge != forwardGraph[i].edges.end(); edge ++){
            if (forwardGraph[i].distance + reverseGraph[edge -> first].distance + 0.5*(edge -> second) < minRoute){
                minRoute = forwardGraph[i].distance + reverseGraph[edge -> first].distance + 0.5*(edge -> second);
            }
        }
    }

    cout << minRoute << "\n";

    return 0;
}
