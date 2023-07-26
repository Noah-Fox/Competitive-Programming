//https://cses.fi/problemset/task/1202

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD_MAX = 1000000007;

void topoSort(vector<vector<ll>>& graph, stack<ll>& revTopoSort, ll onNode, vector<bool>& processed,vector<ll>& pathAmount){
    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        if (!processed[*it]){
            topoSort(graph,revTopoSort,*it,processed,pathAmount);
        }
    }
    processed[onNode] = true;
    revTopoSort.push(onNode);

    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        pathAmount[onNode] += pathAmount[*it];
        pathAmount[onNode] = pathAmount[onNode] % MOD_MAX;
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<vector<pair<ll,ll>>> graph(nodeAmount+1);//store {to node, weight}
    ll a, b, c;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    //run dijkstra
    vector<ll> distance(nodeAmount+1,-1);
    vector<vector<ll>> previousNodes(nodeAmount+1);
    priority_queue<pair<ll,ll>> q;//store {-distance, node}
    vector<bool> processed(nodeAmount+1,false);
    distance[1] = 0;
    q.push({0,1});
    while (!q.empty()){
        ll onNode = q.top().second;
        q.pop();
        if (!processed[onNode]){
            processed[onNode] = true;
            for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
                if (distance[it -> first] == -1 || distance[onNode] + (it -> second) < distance[it -> first]){
                    distance[it -> first] = distance[onNode] + (it -> second);
                    q.push({-distance[it -> first],it -> first});
                    previousNodes[it -> first] = {onNode};
                }
                else if (distance[onNode] + (it -> second) == distance[it -> first]){
                    previousNodes[it -> first].push_back(onNode);
                }
            }
        }
    }

    const ll minPrice = distance[nodeAmount];

    //construct new graph where all paths from beginning to end are minimum price
    vector<vector<ll>> pathGraph(nodeAmount+1);
    for (ll i = 1; i <= nodeAmount; i ++){
        for (auto it = previousNodes[i].begin(); it != previousNodes[i].end(); it ++){
            pathGraph[*it].push_back(i);
        }
    }

    //construct topological sorting and find amount of min-price paths
    stack<ll> revTopoSort;
    vector<bool> topoProcessed(nodeAmount+1,false);
    vector<ll> pathAmount(nodeAmount+1,0);
    pathAmount[nodeAmount] = 1;
    topoSort(pathGraph,revTopoSort,1,topoProcessed,pathAmount);

    const ll minPricePathAmount = pathAmount[1];

    //find the minimum number of flights in a minimum-price path
    stack<ll> spread;
    spread.push(1);
    ll onDist = 0;
    vector<bool> bfProcessed(nodeAmount+1,false);
    ll minPathDist = -1;
    while (!spread.empty()){
        stack<ll> nextSpread;
        while (!spread.empty()){
            ll onNode = spread.top();
            spread.pop();
            if (!bfProcessed[onNode]){
                if (onNode == nodeAmount){
                    minPathDist = onDist;
                }
                bfProcessed[onNode] = true;
                for (auto it = pathGraph[onNode].begin(); it != pathGraph[onNode].end(); it ++){
                    if (!bfProcessed[*it]){
                        nextSpread.push(*it);
                    }
                }
            }
        }
        spread = nextSpread;
        onDist ++;
    }

    //find the maximum number of flights in a minimum-price path
    vector<ll> maxPathDistances(nodeAmount+1,0);
    while (!revTopoSort.empty()){
        ll onNode = revTopoSort.top();
        revTopoSort.pop();
        for (auto it = pathGraph[onNode].begin(); it != pathGraph[onNode].end(); it ++){
            if (maxPathDistances[onNode] + 1 > maxPathDistances[*it]){
                maxPathDistances[*it] = maxPathDistances[onNode] + 1;
            }
        }
    }
    const ll maxPathDist = maxPathDistances[nodeAmount];


    cout << minPrice << " " << minPricePathAmount << " " << minPathDist << " " << maxPathDist << "\n";

    return 0;
}
