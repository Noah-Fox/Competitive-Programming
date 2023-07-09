//https://cses.fi/problemset/task/1197

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    ll from;
    ll to;
    ll weight;
};

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph as an edgeList
    vector<Edge> edges(edgeAmount+1);
    for (ll i = 1; i <= edgeAmount; i ++){
        cin >> edges[i].from;
        cin >> edges[i].to;
        cin >> edges[i].weight;
    }

    //perform bellman-ford algorithm
    vector<ll> distances(nodeAmount+1,9000000000000000000);
    vector<ll> fromNode(nodeAmount+1,0);
    distances[1] = 0;
    ll changeAt = 0;
    for (ll i = 1; i <= nodeAmount; i ++){
        changeAt = 0;
        for (ll j = 1; j <= edgeAmount; j ++){
            if (distances[edges[j].from]+edges[j].weight < distances[edges[j].to]){
                changeAt = edges[j].from;
                fromNode[edges[j].to] = edges[j].from;
                distances[edges[j].to] = distances[edges[j].from]+edges[j].weight;
            }
        }
    }

    //output solution
    //final iteration of bellman-ford gives changeAt -- the last node to be updated 
    if (changeAt == 0){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        
        //retrace steps from changeAt until a loop is reached 
        vector<bool> reached(nodeAmount+1,false);
        stack<ll> loop;
        while (!reached[changeAt]){
            loop.push(changeAt);
            reached[changeAt] = true;
            changeAt = fromNode[changeAt];
        }

        //output the nodes retraced through until you reach the node you started the loop at
        cout << changeAt << " ";
        while (loop.top() != changeAt){
            cout << loop.top() << " ";
            loop.pop();
        }
        cout << changeAt << "\n";
    }

    return 0;
}

//23 4 13 5 18 2 4
