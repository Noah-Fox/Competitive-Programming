//https://open.kattis.com/problems/slowleak

/**
 * Find the shortest path from a to b, such that any distance on the path between two marked nodes (pumps) is less
 * than a given value
 *
 * First run the Floyd-warshall algorithm to find the distance from every node to every other node. Then create an
 * adjacency list representation of the graph using only the pump nodes, and distances between them that are less
 * than the maximum distance. Run dijkstra on this new graph.
*/

// #include <iostream>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 9000000000000000000;

struct Node{
    vector<pair<ll,ll>> edges;//{toNode,edge}
    ll distance = MAX;
    bool processed = false;
};

int main(){
    // ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount, pumpAmount, maxDist;
    cin >> nodeAmount >> edgeAmount >> pumpAmount >> maxDist;

    //input pumps
    pumpAmount += 2;
    vector<ll> pumps(pumpAmount);
    pumps[0] = 1;
    pumps[1] = nodeAmount;
    ll a, b, w;
    for (ll i = 2; i < pumpAmount; i ++){
        cin >> pumps[i];
    }

    //input graph as adjacency matrix
    vector<vector<ll>> distance(nodeAmount+1,vector<ll>(nodeAmount+1,MAX));
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b >> w;
        distance[a][b] = w;
        distance[b][a] = w;
    }

    for (ll i = 1; i <= nodeAmount; i ++){
        distance[i][i] = 0;
    }


    //run floyd-warshall using all nodes
    for (ll k = 1; k <= nodeAmount; k ++){
        for (ll i = 1; i <= nodeAmount; i ++){
            for (ll j = 1; j <= nodeAmount; j ++){
                if (distance[i][k] != MAX && distance[k][j] != MAX){
                    distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
    }

    //create graph using pumps
    vector<Node> graph(nodeAmount+1);
    for (ll i = 0; i < pumpAmount; i ++){
        for (ll j = i+1; j < pumpAmount; j ++){
            if (distance[pumps[i]][pumps[j]] <= maxDist){
                graph[pumps[i]].edges.push_back({pumps[j],distance[pumps[i]][pumps[j]]});
                graph[pumps[j]].edges.push_back({pumps[i],distance[pumps[i]][pumps[j]]});
            }
        }
    }

    //run dijkstra on pumps
    priority_queue<pair<ll,ll>> q;//{-weight,node}
    q.push({0,1});
    graph[1].distance = 0;
    while (!q.empty()){
        ll onNode = q.top().second;
        q.pop();
        if (!graph[onNode].processed){
            graph[onNode].processed = true;
            for (auto it = graph[onNode].edges.begin(); it != graph[onNode].edges.end(); it ++){
                ll toNode = it -> first;
                ll weight = it -> second;
                if (graph[onNode].distance + weight < graph[toNode].distance){
                    graph[toNode].distance = graph[onNode].distance + weight;
                    q.push({-graph[toNode].distance,toNode});
                }
            }
        }
    }

    //output solution
    if (graph[nodeAmount].distance < MAX){
        cout << graph[nodeAmount].distance << "\n";
    }
    else {
        cout << "stuck\n";
    }

    return 0;
}
