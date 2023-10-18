//https://open.kattis.com/contests/w9i5jp/problems/squawk

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll nodeAmount, edgeAmount, initial, time;
    cin >> nodeAmount >> edgeAmount >> initial >> time;

    //input graph
    vector<vector<ll>> graph(nodeAmount);
    ll a, b;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //simulate spread
    vector<ll> pastCount(nodeAmount,0);
    pastCount[initial] = 1;
    for (ll i = 0; i < time; i ++){
        vector<ll> currentCount(nodeAmount,0);
        for (ll j = 0; j < nodeAmount; j ++){
            for (auto it = graph[j].begin(); it != graph[j].end(); it ++){
                currentCount[j] += pastCount[*it];
            }
        }
        pastCount = currentCount;
    }

    ll sum = 0;
    for (ll i = 0; i < nodeAmount; i ++){
        sum += pastCount[i];
    }

    cout << sum << "\n";

    return 0;
}
