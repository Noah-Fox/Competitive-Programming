//https://cses.fi/problemset/task/1678

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<vector<ll>>& graph, vector<bool>& processed, vector<bool>& inPath, ll onNode, stack<ll>& loop, ll& loopSize){
    inPath[onNode] = true;
    for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
        if (inPath[*it]){
            loop.push(*it);
            loop.push(onNode);
            return *it;
        }
        else if (!processed[*it]){
            processed[*it] = true;
            ll a = solve(graph,processed,inPath,*it,loop,loopSize);
            if (!loop.empty()){
                if (a > 0){
                    loop.push(onNode);
                    loopSize ++;
                    if (a == onNode){
                        a = 0;
                    }
                }
                return a;
            }
        }
    }
    inPath[onNode] = false;
    return 0;
}

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
    }

    //solve
    vector<bool> inPath(nodeAmount+1,false);
    vector<bool> processed(nodeAmount+1,false);
    stack<ll> loop;
    ll loopSize = 0;
    for (ll i = 1; i <= nodeAmount; i ++){
        if (!processed[i]){
            solve(graph,processed,inPath,i,loop,loopSize);
            if (loopSize > 0){
                cout << loopSize+2 << "\n";
                while (!loop.empty()){
                    cout << loop.top() << " ";
                    loop.pop();
                }
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
