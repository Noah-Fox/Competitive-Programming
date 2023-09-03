//https://open.kattis.com/problems/crosscountry

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const ll MAX = 1000000007;

int main(){
    ll nodeAmount, startNode, endNode;
    cin >> nodeAmount >> startNode >> endNode;

    vector<vector<ll>> graph(nodeAmount,vector<ll>(nodeAmount));
    //input graph
    for (ll i = 0; i < nodeAmount; i ++){
        for (ll x = 0; x < nodeAmount; x ++){
            cin >> graph[i][x];
        }
    }

    //run dijkstra
    vector<ll> distance(nodeAmount,MAX);
    distance[startNode] = 0;
    priority_queue<pair<ll,ll>> q;//stores {-distance, id}
    q.push({0,startNode});
    vector<bool> processed(nodeAmount,false);
    while (!q.empty()){
        ll onNode = q.top().second;
        q.pop();
        if (!processed[onNode]){
            processed[onNode] = true;
            for (ll i = 0; i < nodeAmount; i ++){
                if (distance[onNode] + graph[onNode][i] < distance[i]){
                    distance[i] = distance[onNode] + graph[onNode][i];
                    q.push({-distance[i],i});
                }
            }
        }
    }

    //output solution
    cout << distance[endNode] << "\n";


    return 0;
}
