//https://cses.fi/problemset/task/1669

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(vector<vector<ll>>& graph, vector<ll>& fromNode, ll startNode){
    fromNode[startNode] = startNode;
    stack<ll> spread;
    spread.push(startNode);
    //spread from the starting point one layer at a time, recording the node each node was spread to from
    while (!spread.empty()){
        stack<ll> nextSpread;
        while (!spread.empty()){
            for (size_t i = 0; i < graph[spread.top()].size(); i ++){
                ll toNode = graph[spread.top()][i];
                if (fromNode[toNode] == 0){
                    nextSpread.push(toNode);
                    fromNode[toNode] = spread.top();

                }
                //output solution
                //a loop is found once you reach a node that has been spread to already (and wasn't just spread from)
                else if (toNode != fromNode[spread.top()]){
                    ll pathLength = 0;
                    stack<ll> path1;

                    //go from the current node to the starter node, recording each one and setting their previous
                    //  node values to -1
                    path1.push(toNode);
                    path1.push(spread.top());
                    while (path1.top() != startNode){
                        pathLength ++;
                        ll holdPath1Top = path1.top();
                        path1.push(fromNode[path1.top()]);
                        fromNode[holdPath1Top] = -1;
                    }
                    fromNode[startNode] = -1;

                    queue<ll> path2;
                    path2.push(toNode);
                    ll nextNode = toNode;
                    
                    //go from current node to first node that has previous marked as -1
                    while (fromNode[nextNode] != -1){
                        pathLength ++;
                        path2.push(fromNode[nextNode]);
                        nextNode = fromNode[nextNode];
                    }

                    while (path1.top() != nextNode){
                        pathLength --;
                        path1.pop();
                    }
                    pathLength += 2;
                    path1.pop();

                    cout << pathLength << "\n";

                    while (!path2.empty()){
                        cout << path2.front() << " ";
                        path2.pop();
                    }
                    while (!path1.empty()){
                        cout << path1.top() << " ";
                        path1.pop();
                    }
                    cout << "\n";
                    return true;
                }
            }
            spread.pop();
        }
        spread = nextSpread;
    }
    return false;
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
        graph[b].push_back(a);
    }

    //solve
    vector<ll> fromNode(nodeAmount+1,0);
    //every time you find a new component of the graph that hasn't been tested for a loop, test it
    for (ll i = 1; i <= nodeAmount; i ++){
        if (fromNode[i] == 0){
            if (solve(graph, fromNode, i)){
                return 0;
            }
        }
    }
    

    cout << "IMPOSSIBLE\n";

    return 0;
}
