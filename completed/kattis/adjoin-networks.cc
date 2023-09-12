//https://open.kattis.com/problems/adjoin

/*
 * Given a graph consisting of any number of disconnected trees, determine the maximum distance between any two nodes
 * if all trees are optimally connected into one tree in a way that minimizes this distance
 *
 * Iterate through each node of the graph. Every time you reach a tree that has not been processed:
 *  1. Perform depth-first search on the tree recursively
 *      - after recursing back up, use the returned solutions of the children to find the two highest distances
 * from the node to its descendants
 *  2. Perform depth-first search on the tree again
 *      - as you recurse down, use the solution of the parent to find the two highest distances from the node to
 * any other node
 *      - find the node with the lowest maximum distance - this is the root of the tree that will be used to connect to
 * other trees
 *  3. Record the three highest distances of roots, and the second distance of the highest root
 *
 * The connections between the trees are made from each tree to the tree with the highest root. Cases:
 *  1. The highest root is higher than all other roots, and its second distance is higher than all roots: return the sum
 * of its two highest distances
 *  2. The highest root is higher than all other roots, but its second distance is not: return the sum of the two highest
 * roots plus one
 *  3. The highest root has the same distance as the next two highest roots: return the sum of the two highest roots plus one
*/

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    vector<ll> edges;
    ll processedLevel = 0;
    
    ll furthestChild = -1;//child with furthest distance to a descendant
    ll furthestChildDist = 0;//distance to furthest descendant through furthestChild
    ll secondChild = -1;//child with second furthest distance to a descendant
    ll secondChildDist = 0;//distance to furthest descendant through secondChild

    ll parentDist = 0;//distance through parent

    ll maxDist = 0;//maximum distance to any other node
    ll secondMaxDist = 0;//second furthest distance to any other node
};

/**
 * given an adjacency list and a value for the current node, recursively determines the values 
 * furthestChild, furthestChildDist, secondChild, and secondChildDist
 *
 * returns furthestChildDist
*/
ll childDistances(vector<Node>& graph, ll onNode){
    graph[onNode].processedLevel = 1;

    ll childDist;

    //iterate through each child, and
    for (auto it = graph[onNode].edges.begin(); it != graph[onNode].edges.end(); it ++){
        if (graph[*it].processedLevel == 0){
            childDist = childDistances(graph,*it)+1;
            if (childDist > graph[onNode].secondChildDist){
                //assign second child to *it if greater
                graph[onNode].secondChildDist = childDist;
                graph[onNode].secondChild = *it;

                //swap second and first child if greater
                if (childDist > graph[onNode].furthestChildDist){
                    swap(graph[onNode].furthestChildDist,graph[onNode].secondChildDist);
                    swap(graph[onNode].furthestChild,graph[onNode].secondChild);
                }
            }
        }
    }


    return graph[onNode].furthestChildDist;
}

/*
 * Given an adjacency list, the current node, and the parent, determine the highest and second
 * highest distances from the node to any other node in the graph. Return these values in a pair
*/
pair<ll,ll> parentDistance(vector<Node>& graph, ll onNode, ll parent){
    graph[onNode].processedLevel = 2;

    //determine longest path through parent
    if (parent != -1){
        ll siblingDist = graph[parent].furthestChildDist;
        if (graph[parent].furthestChild == onNode){
            siblingDist = graph[parent].secondChildDist;
        }
        graph[onNode].parentDist = max(siblingDist,graph[parent].parentDist)+1;
    }
    
    //recurse to children
    ll minMax = max(graph[onNode].parentDist,graph[onNode].furthestChildDist);
    graph[onNode].maxDist = minMax;
    if (graph[onNode].parentDist > graph[onNode].furthestChildDist){
        graph[onNode].secondMaxDist = graph[onNode].furthestChildDist;
    }
    else {
        graph[onNode].secondMaxDist = max(graph[onNode].secondChildDist,graph[onNode].parentDist);
    }
    ll secondMinMax = graph[onNode].secondMaxDist;
    for (auto it = graph[onNode].edges.begin(); it != graph[onNode].edges.end(); it ++){
        if (graph[*it].processedLevel == 1){
            pair<ll,ll> getDist = parentDistance(graph,*it,onNode);
            if (minMax > getDist.first){
                minMax = getDist.first;
                secondMinMax = getDist.second;
            }
        }
    }

    return {minMax,secondMinMax};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll nodeAmount, edgeAmount;
    cin >> nodeAmount >> edgeAmount;

    //special case: there is only one node
    if (nodeAmount == 1){
        cout << "0\n";
        return 0;
    }
    //special case: there are only two nodes
    if (nodeAmount == 2){
        cout << "1\n";
        return 0;
    }

    //input graph
    vector<Node> graph(nodeAmount);
    ll a, b;
    for (ll i = 0; i < edgeAmount; i ++){
        cin >> a >> b;
        graph[a].edges.push_back(b);
        graph[b].edges.push_back(a);
    }

    //process through all nodes
    ll dist1 = 0;
    ll dist2 = 0;
    ll dist3 = 0;
    ll secondDist = 0;
    pair<ll,ll> distances;
    ll dist;
    for (ll i = 0; i < nodeAmount; i ++){
        if (graph[i].processedLevel == 0){

            //recursion 1
            childDistances(graph,i);

            //recursion 2
            distances = parentDistance(graph,i,-1);
            dist = distances.first;

            if (dist > dist3){
                dist3 = dist;
                if (dist3 > dist2){
                    swap(dist3,dist2);
                    if (dist2 > dist1){
                        swap(dist2,dist1);
                        secondDist = distances.second;
                    }
                }
            }
        }
    }

    //output solution
    if (secondDist > dist2){
        cout << dist1 + secondDist << "\n";
    }
    else if (dist1 == dist2 && dist2 == dist3){
        cout << dist1 + dist2 + 2 << "\n";
    }
    else {
        cout << dist1 + dist2 + 1 << "\n";
    }

    return 0;
}
