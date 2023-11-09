//https://open.kattis.com/problems/intercept

/*
 * Given a weighted, directed graph with start node a and end node b, with a guaranteed path from a to b, determine
 * which nodes are on every shortest path from a to b
 *
 * First, find all paths from a to be with the same minimal length, and determine for each node every node before
 * it on these paths. To do this, run dijkstra. Every time you process an edge of weight w from u to v, if the edge
 * shortens the distance to v, replace v's list of previous nodes with {u}. If it is equal to its distance, add u 
 * to the list.
 *
 * Next, for each node, find the number of nodes immediately after it on a shortest path. To do this, perform breadth
 * first search starting at node b, using the previous nodes to spread. Every time a node is reached, increment its
 * count.
 *
 * To determine which nodes are on every shortest path, do another breadth first search. Records the number of "live"
 * nodes -- nodes which have been reached but have not been processed yet. A node becomes live when it is reached for
 * the first time. A node is added to the queue when it has been reached by every node leading into it. A node is on 
 * every shortest path if it is the only live node when it is being processed.
*/

// #include <iostream>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<pair<ll,ll>> children;//{node, weight}
    vector<ll> prevChildren;//nodes that precede on a shortest path
    ll parentAmount = 0;
    ll distance = 1000000000000007;
    bool processed = false;
    ll iterCount = 0;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //input graph
    vector<Node> graph(nodeAmount);
    ll u, v, w;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> u >> v >> w;
        graph[u].children.push_back({v,w});
    }
    ll startNode, endNode;
    cin >> startNode >> endNode;

    //run modified dijkstra
    priority_queue<pair<ll,ll>> q;//{-distance, node id}
    graph[startNode].distance = 0;
    q.push({0,startNode});
    while (!q.empty()){
        ll onNode = q.top().second;
        q.pop();
        if (!graph[onNode].processed){
            graph[onNode].processed = true;
            for (auto it = graph[onNode].children.begin(); it != graph[onNode].children.end(); it ++){
                ll newDist = graph[onNode].distance + (it -> second);
                if (newDist < graph[it -> first].distance){
                    graph[it -> first].distance = newDist;
                    graph[it -> first].prevChildren = {onNode};
                    q.push({-newDist,it -> first});
                }
                else if (newDist == graph[it -> first].distance){
                    graph[it -> first].prevChildren.push_back(onNode);
                }
            }
        }
    }

    //find the parentAmount of each node
    queue<ll> iterQ;
    iterQ.push(endNode);
    while (!iterQ.empty()){
        ll onNode = iterQ.front();
        iterQ.pop();
        for (auto it = graph[onNode].prevChildren.begin(); it != graph[onNode].prevChildren.end(); it ++){
            graph[*it].parentAmount ++;
            if (graph[*it].parentAmount == 1){
                iterQ.push(*it);
            }
        }
    }

    //iterate backward
    vector<ll> solutionNodes;
    ll liveNodeAmount = 1;
    iterQ.push(endNode);
    while (!iterQ.empty()){
        ll onNode = iterQ.front();
        iterQ.pop();

        //if current node is the only live node, it is on every path
        if (liveNodeAmount == 1){
            solutionNodes.push_back(onNode);
        }

        //node is no longer live after spreading to children
        liveNodeAmount --;

        //spread to children
        for (auto it = graph[onNode].prevChildren.begin(); it != graph[onNode].prevChildren.end(); it ++){
            //a node becomes live when it is reached for the first time
            if (graph[*it].iterCount == 0){
                liveNodeAmount ++;
            }

            //increment node's iterCount
            graph[*it].iterCount ++;

            //add node to queue if every parent has reached it
            if (graph[*it].iterCount == graph[*it].parentAmount){
                iterQ.push(*it);
            }
        }
    }

    //output solution
    sort(solutionNodes.begin(),solutionNodes.end());
    for (auto it = solutionNodes.begin(); it != solutionNodes.end(); it ++){
        cout << *it << " ";
    }
    cout << "\n";
    

    return 0;
}
