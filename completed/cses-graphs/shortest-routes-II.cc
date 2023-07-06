//https://cses.fi/problemset/task/1672

/**
 * Use Floyd-Warshall algorithm
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount, queryAmount;
    cin >> nodeAmount >> edgeAmount >> queryAmount;

    vector<vector<ll>> distance(nodeAmount+1,vector<ll>(nodeAmount+1,-1));
    for (ll i = 1; i <= nodeAmount; i ++){
        distance[i][i] = 0;
    }

    //input graph
    ll a, b, c;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b >> c;
        if (distance[a][b] == -1 || c < distance[a][b]){
            distance[a][b] = c;
            distance[b][a] = c;
        }
    }

    //run floyd-warshall
    for (ll k = 1; k <= nodeAmount; k ++){
        for (ll i = 1; i <= nodeAmount; i ++){
            for (ll j = 1; j <= nodeAmount; j ++){
                if (distance[i][k] != -1 && distance[k][j] != -1){
                    if (distance[i][j] == -1){
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                    else {
                        distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
                    }
                }
            }
        }
    }

    //answer queries
    for (ll i = 0; i < queryAmount; i ++){
        cin >> a >> b;
        cout << distance[a][b] << "\n";
    }

    return 0;
}
