//https://cses.fi/problemset/task/1671

// #include <iostream>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<vector<pair<ll,ll>>> graph(nodeAmount+1);
    ll a, b, c;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    vector<ll> distance(nodeAmount+1,-1);
    distance[1] = 0;

    priority_queue<pair<ll,ll>> q;
    q.push({0,1});

    vector<bool> processed(nodeAmount+1,false);

    while (!q.empty()){
        ll onNode = q.top().second;
        if (!processed[onNode]){
            processed[onNode] = true;
            for (size_t i = 0; i < graph[onNode].size(); i ++){
                if (distance[onNode] + graph[onNode][i].second < distance[graph[onNode][i].first] || distance[graph[onNode][i].first] == -1){
                    distance[graph[onNode][i].first] = distance[onNode] + graph[onNode][i].second;
                    q.push({-distance[graph[onNode][i].first],graph[onNode][i].first});
                }
            }
        }
        q.pop();
    }

    for (ll i = 1; i <= nodeAmount; i ++){
        cout << distance[i] << "\n";
    }

    return 0;
}
