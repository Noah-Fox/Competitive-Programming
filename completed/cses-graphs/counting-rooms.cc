//https://cses.fi/problemset/task/1192

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void spread(vector<vector<ll>>& graph, vector<bool>& marked, ll onNode){
    for (int i = 0; i < graph[onNode].size(); i ++){
        if (!marked[graph[onNode][i]]){
            marked[graph[onNode][i]] = true;
            spread(graph, marked, graph[onNode][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;

    vector<vector<ll>> building(h, vector<ll>(w,0));

    ll onNode = 0;
    for (int i = 0; i < h; i ++){
        cin.ignore();
        for (int x = 0; x < w; x ++){
            if (cin.peek() == '.'){
                onNode ++;
                building[i][x] = onNode;
            }
            cin.ignore();
        }
    }

    vector<vector<ll>> graph(onNode+1);
    vector<bool> marked(onNode+1,false);

    for (int i = 0; i < h; i ++){
        for (int x = 0; x < w; x ++){
            if (building[i][x]){
                if (i > 0 && building[i-1][x]){
                    graph[building[i][x]].push_back(building[i-1][x]);
                }
                if (i < h-1 && building[i+1][x]){
                    graph[building[i][x]].push_back(building[i+1][x]);
                }
                if (x > 0 && building[i][x-1]){
                    graph[building[i][x]].push_back(building[i][x-1]);
                }
                if (x < w-1 && building[i][x+1]){
                    graph[building[i][x]].push_back(building[i][x+1]);
                }
            }
        }
    }

    ll roomAmount = 0;
    for (int i = 1; i <= onNode; i ++){
        if (!marked[i]){
            roomAmount ++;
            spread(graph,marked,i);
        }
    }

    cout << roomAmount << "\n";
    

    return 0;
}
