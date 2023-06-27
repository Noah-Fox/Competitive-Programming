//https://cses.fi/problemset/task/1193

#include <iostream>
#include <vector>
#include <stack>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    string path = "";
    bool isWall = true;
    ll dist = -1;
};

int main(){
    ios::sync_with_stdio(0);

    ll height, width;
    cin >> height >> width;

    pair<ll,ll> start, end;

    vector<vector<Node>> graph(height+2, vector<Node>(width+2));
    for (ll i = 1; i <= height; i ++){
        cin.ignore();
        for (ll x = 1; x <= width; x ++){
            if (cin.peek() != '#'){
                graph[i][x].isWall = false;
            }
            if (cin.peek() == 'A'){
                graph[i][x].dist = 0;
                start = {i,x};
            }
            else if (cin.peek() == 'B'){
                end = {i,x};
            }
            cin.ignore();
        }
    }

    stack<pair<ll,ll>> toProcess;
    stack<pair<ll,ll>> nextProcess;
    toProcess.push(start);
    while (!toProcess.empty()){
        while (!nextProcess.empty()) nextProcess.pop();
        while (!toProcess.empty()){
            ll onY = toProcess.top().first;
            ll onX = toProcess.top().second;
            
            if (toProcess.top() == end){
                cout << "YES\n" << graph[onY][onX].dist << "\n" << graph[onY][onX].path << "\n";
                return 0;
            }

            if (!graph[onY-1][onX].isWall && graph[onY-1][onX].dist == -1){
                graph[onY-1][onX].dist = graph[onY][onX].dist+1;
                graph[onY-1][onX].path = graph[onY][onX].path+'U';
                nextProcess.push({onY-1,onX});
            }
            if (!graph[onY+1][onX].isWall && graph[onY+1][onX].dist == -1){
                graph[onY+1][onX].dist = graph[onY][onX].dist+1;
                graph[onY+1][onX].path = graph[onY][onX].path+'D';
                nextProcess.push({onY+1,onX});
            }
            if (!graph[onY][onX-1].isWall && graph[onY][onX-1].dist == -1){
                graph[onY][onX-1].dist = graph[onY][onX].dist+1;
                graph[onY][onX-1].path = graph[onY][onX].path+'L';
                nextProcess.push({onY,onX-1});
            }
            if (!graph[onY][onX+1].isWall && graph[onY][onX+1].dist == -1){
                graph[onY][onX+1].dist = graph[onY][onX].dist+1;
                graph[onY][onX+1].path = graph[onY][onX].path+'R';
                nextProcess.push({onY,onX+1});
            }
            toProcess.pop();
        }
        toProcess = nextProcess;
    }

    cout << "NO\n";

    return 0;
}
