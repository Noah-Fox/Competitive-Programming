//https://cses.fi/problemset/task/1667

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

    //solve
    vector<ll> fromNode(nodeAmount+1,0);
    fromNode[1] = 1;
    stack<ll> spread;
    spread.push(1);
    while (!spread.empty()){
        stack<ll> nextSpread;
        while (!spread.empty()){
            for (size_t i = 0; i < graph[spread.top()].size(); i ++){
                ll toNode = graph[spread.top()][i];
                if (fromNode[toNode] == 0){
                    nextSpread.push(toNode);
                    fromNode[toNode] = spread.top();

                    //output solution
                    if (toNode == nodeAmount){
                        stack<ll> outputStack;
                        outputStack.push(nodeAmount);
                        ll pathLength = 1;
                        while (outputStack.top() != 1){
                            outputStack.push(fromNode[outputStack.top()]);
                            pathLength ++;
                        }
                        cout << pathLength << "\n";
                        while (!outputStack.empty()){
                            cout << outputStack.top() << " ";
                            outputStack.pop();
                        }
                        cout << "\n";
                        return 0;
                    }
                }
            }
            spread.pop();
        }
        spread = nextSpread;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
