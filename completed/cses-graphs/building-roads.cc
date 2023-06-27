//https://cses.fi/problemset/task/1666

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void spread(vector<vector<ll>>& graph, vector<bool>& marked, ll onNode){
    for (ll i = 0; i < graph[onNode].size(); i ++){
        if (!marked[graph[onNode][i]]){
            marked[graph[onNode][i]] = true;
            spread(graph,marked,graph[onNode][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll cityAmount, roadAmount;
    cin >> cityAmount >> roadAmount;

    vector<vector<ll>> graph(cityAmount+1);
    vector<bool> marked(cityAmount+1,false);

    ll a, b;
    for (ll i = 0; i < roadAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll makeAmount = 0;
    vector<ll> makeRoadsTo;

    for (ll i = 1; i <= cityAmount; i ++){
        if (!marked[i]){
            makeAmount ++;
            makeRoadsTo.push_back(i);
            spread(graph,marked,i);
        }
    }

    cout << makeAmount-1 << "\n";
    for (size_t i = 1; i < makeRoadsTo.size(); i ++){
        cout << "1 " << makeRoadsTo[i] << "\n";
    }

    return 0;
}
