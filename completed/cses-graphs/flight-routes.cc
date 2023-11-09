//https://cses.fi/problemset/task/1196

/**
 * use modified dijkstra
*/

#include <iostream>
#include <vector>
#include <queue>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount, pathAmount;
    cin >> nodeAmount >> edgeAmount >> pathAmount;

    //input graph
    vector<vector<pair<ll,ll>>> graph(nodeAmount+1);//{to node, weight}
    ll from, to, weight;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> from >> to >> weight;
        graph[from].push_back({to,weight});
    }

    //solve
    priority_queue<pair<ll,ll>> q;//{-distance to node, node}
    q.push({0,1});
    vector<ll> count(nodeAmount+1,0);
    while (count[nodeAmount] < pathAmount){
        ll onDist = -q.top().first;
        ll onNode = q.top().second;
        q.pop();
        if (count[onNode] < pathAmount){
            count[onNode] ++;

            //path of length onDist is found to goal node
            if (onNode == nodeAmount){
                cout << onDist << "\n";
            }

            //spread through all edges
            for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
                q.push({-(it -> second)-onDist,it -> first});
            }
        }
    }

    return 0;
}
