//https://cses.fi/problemset/task/1679

/**
 * Given a list of pairs of nodes (a,b), where a needs to be processed before b, output all nodes in order
 *
 * For each node, store the nodes it needs to be processed before, and the number of nodes that need to be
 * processed before it (preAmount). Store all nodes with preAmount=0 in a queue. While the queue isn't empty,
 * remove the front node, process it, decrement the preAmount value for each following node, and add each 
 * following node with preAmount=0 to the queue.
*/

// #include <iostream>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<vector<ll>> graph(nodeAmount+1);
    vector<ll> preAmount(nodeAmount+1,0);
    ll a, b;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        preAmount[b] ++;
    }

    //solve
    queue<ll> freeNodes;
    vector<bool> processed(nodeAmount+1,false);
    queue<ll> solution;
    ll processedAmount = 0;
    for (ll i = 1; i <= nodeAmount; i ++){
        if (preAmount[i] == 0){
            freeNodes.push(i);
        }
    }
    while (!freeNodes.empty()){
        ll onNode = freeNodes.front();
        freeNodes.pop();
        if (!processed[onNode]){
            processed[onNode] = true;
            solution.push(onNode);
            processedAmount ++;
            for (auto it = graph[onNode].begin(); it != graph[onNode].end(); it ++){
                preAmount[*it] --;
                if (preAmount[*it] == 0){
                    freeNodes.push(*it);
                }
            }
        }
    }

    //output solution
    if (processedAmount == nodeAmount){
        while (!solution.empty()){
            cout << solution.front() << "\n";
            solution.pop();
        }
    }
    else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
