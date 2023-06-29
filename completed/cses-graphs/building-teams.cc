//https://cses.fi/problemset/task/1668

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<vector<ll>> graph(nodeAmount+1);
    ll a, b;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> onTeam(nodeAmount+1,0);

    for (ll i = 1; i <= nodeAmount; i ++){
        if (onTeam[i] == 0){
            onTeam[i] = 1;
            int setTeam = 2;
            stack<ll> spreadTeam;
            spreadTeam.push(i);
            while (!spreadTeam.empty()){
                stack<ll> nextSpread;
                while (!spreadTeam.empty()){
                    for (size_t x = 0; x < graph[spreadTeam.top()].size(); x ++){
                        ll toNode = graph[spreadTeam.top()][x];
                        if (onTeam[toNode] == 0){
                            onTeam[toNode] = setTeam;
                            nextSpread.push(toNode);
                        }
                        else if (onTeam[toNode] != setTeam){
                            cout << "IMPOSSIBLE\n";
                            return 0;
                        }
                    }
                    spreadTeam.pop();
                }
                spreadTeam = nextSpread;
                setTeam = setTeam % 2 + 1;
            }
        }
    }

    for (ll i = 1; i <= nodeAmount; i ++){
        cout << onTeam[i] << " ";
    }
    cout << "\n";

    return 0;
}
