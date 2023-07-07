//https://cses.fi/problemset/task/1673


/**
 * Use bellman-ford algorithm to solve
 *
 * Flip sign of all weights - algorithm finds the lowest path without any negative loops, we want the
 * highest path without any positive loops. Flip sign of final solution at the end.
 *
 * Algorithm detects all negative loops, but the only time they affect the solution is if they are on
 * the path from the 1st to nth node. To avoid this, perform two depth-first searches: first from the 1st
 * node using normal edges, then from the nth node using reversed edges. Record what nodes are reached for
 * each. When running algorithm, only flag negative loops if the node is reached in both searches.
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    ll from;
    ll to;
    ll weight;
};

void spread(vector<vector<ll>>& graph, vector<bool>& reached, ll onNode, ll fromNode){
    reached[onNode] = true;
    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        if (*it != fromNode && !reached[*it]){
            spread(graph, reached, *it, onNode);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;
    
    //input graph as an edge list
    vector<Edge> edges(edgeAmount);
    vector<vector<ll>> graph(nodeAmount+1);
    vector<vector<ll>> reverseGraph(nodeAmount+1);
    ll f, t, w;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> f >> t >> w;
        edges[i].from = f;
        edges[i].to = t;
        edges[i].weight = -w;
        graph[f].push_back(t);
        reverseGraph[t].push_back(f);
    }

    //find nodes that can be reached from the start
    vector<bool> fromStart(nodeAmount, false);
    spread(graph,fromStart,1,0);

    //find nodes that reach the start
    vector<bool> reachEnd(nodeAmount,false);
    spread(reverseGraph,reachEnd,nodeAmount,0);

    //perform bellman-ford algorithm
    vector<ll> distances(nodeAmount+1,0);
    vector<bool> reached(nodeAmount+1,false);
    reached[1] = true;
    bool hasShortened = false;
    for (ll i = 0; i < nodeAmount; i ++){
        hasShortened = false;
        for (auto edge = edges.begin(); edge != edges.end(); edge ++){
            if (reached[edge -> from]){
                if (!reached[edge -> to] || distances[edge -> to] > distances[edge -> from] + (edge -> weight)){
                    reached[edge -> to] = true;
                    distances[edge -> to] = distances[edge -> from] + (edge -> weight);
                    if (fromStart[edge -> to] && reachEnd[edge -> to]){
                        hasShortened = true;
                    }
                }
            }
        }
    }

    if (hasShortened){
        cout << "-1\n";
    }
    else {
        cout << -distances[nodeAmount] << "\n";
    }

    return 0;
}
