//https://cses.fi/problemset/task/1750

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    ll toNode;
    bool inLoop = false;
    ll loopSize = 0;
    ll distToLoop = 0;
    vector<ll> prevNodes;
    vector<pair<ll,ll>> queries;//{query id, query distance}
};

ll findLoopRecurse(vector<Node>& nodes, ll onNode, vector<ll>& phases, ll onPhase, vector<ll>& roots){
    //base case: current node has been processed (a loop has been made)
    if (phases[onNode] > 0){
        nodes[onNode].inLoop = true;
        nodes[onNode].loopSize = onPhase - phases[onNode];
        onPhase -= phases[onNode];
        return onNode;
    }

    phases[onNode] = onPhase;

    //base case: node points to itself
    if (nodes[onNode].toNode == onNode){
        nodes[onNode].inLoop = true;
        nodes[onNode].loopSize = 1;
        return 0;
    }

    //add current node to next node's prevNodes
    ll nextNode = nodes[onNode].toNode;
    nodes[nextNode].prevNodes.push_back(onNode);

    //base case: next node has a loopSize value
    if (nodes[nextNode].loopSize > 0){
        nodes[onNode].loopSize = nodes[nextNode].loopSize;
        if (nodes[nextNode].inLoop){
            nodes[onNode].distToLoop = 1;
            roots.push_back(onNode);
        }
        else {
            nodes[onNode].distToLoop = nodes[nextNode].distToLoop + 1;
        }
        return 0;
    }

    //recursive case: call next node and get values
    ll loopNode = findLoopRecurse(nodes, nextNode, phases, onPhase+1, roots);
    if (loopNode == 0){
        nodes[onNode].loopSize = nodes[nextNode].loopSize;
        nodes[onNode].distToLoop = nodes[nextNode].distToLoop + 1;
        if (nodes[onNode].distToLoop == 1){
            roots.push_back(onNode);
        }
        return 0;
    }
    if (loopNode == onNode){
        return 0;
    }
    nodes[onNode].inLoop = true;
    nodes[onNode].loopSize = nodes[nextNode].loopSize;
    return loopNode;
}

void solveTree(vector<Node>& nodes, ll onNode, vector<ll>& path, ll onLevel, ll loopPoint, vector<ll>& querySolutions){
    path[onLevel] = onNode;
    //go through every query for the current node
    for (auto it = nodes[onNode].queries.begin(); it != nodes[onNode].queries.end(); it ++){
        if (it -> second <= onLevel){
            querySolutions[it -> first] = path[onLevel - (it -> second)];
        }
        else {
            nodes[loopPoint].queries.push_back({it -> first, (it -> second) - onLevel - 1});
        }
    }
    //recurse to each child
    for (auto it = nodes[onNode].prevNodes.begin(); it != nodes[onNode].prevNodes.end(); it ++){
        solveTree(nodes, *it, path, onLevel + 1, loopPoint, querySolutions);
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll nodeAmount, queryAmount;
    cin >> nodeAmount >> queryAmount;

    //input nodes
    vector<Node> nodes(nodeAmount+1);
    for (ll i = 1; i <= nodeAmount; i ++){
        cin >> nodes[i].toNode;
    }

    //assign queries to nodes
    vector<ll> querySolutions(queryAmount+1,0);
    ll n, d;
    for (ll i = 1; i <= queryAmount; i ++){
        cin >> n >> d;
        nodes[n].queries.push_back({i,d});
    }

    //for each node, determine if it is in a loop/its distance to a loop and the size of the loop
    vector<ll> roots;
    for (ll i = 1; i <= nodeAmount; i ++){
        if (nodes[i].loopSize == 0){
            vector<ll> phases(nodeAmount+1,0);
            findLoopRecurse(nodes, i, phases, 1, roots);
        }
    }

    //go through all trees in the graph
    vector<ll> path(nodeAmount+1,-1);
    for (auto it = roots.begin(); it != roots.end(); it ++){
        solveTree(nodes, *it, path, 0, nodes[*it].toNode, querySolutions);
    }

    //go through all loops
    vector<bool> processed(nodeAmount+1,false);
    for (ll i = 1; i <= nodeAmount; i ++){
        if (nodes[i].inLoop && !processed[i]){
            ll loopSize = nodes[i].loopSize;
            vector<ll> loop(loopSize);
            ll onNode = i;
            //create vector of the loop
            for (ll x = 0; x < loopSize; x ++){
                loop[x] = onNode;
                onNode = nodes[onNode].toNode;
            }

            //process queries in every node of loop
            for (ll x = 0; x < loopSize; x ++){
                processed[loop[x]] = true;
                for (auto it = nodes[loop[x]].queries.begin(); it != nodes[loop[x]].queries.end(); it ++){
                    querySolutions[it -> first] = loop[(it -> second + x) % loopSize];
                }
            }
        }
    }

    //output solution
    for (ll i = 1; i <= queryAmount; i ++){
        cout << querySolutions[i] << "\n";
    }

    return 0;
}
