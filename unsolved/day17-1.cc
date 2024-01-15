//Advent of code day 17 puzzle 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main(){
    string inLine;
    vector<vector<ll>> graph;
    while (getline(cin,inLine)){
        vector<ll> inNums(inLine.length());
        for (size_t i = 0; i < inLine.length(); i ++){
            inNums[i] = inLine[i]-'0';
        }
        graph.push_back(inNums);
    }

    ll graphWidth = graph[0].size();
    ll graphHeight = graph.size();

    vector<vector<ll>> heatLoss(graphHeight,vector<ll>(graphWidth,200000));
    heatLoss[0][0] = graph[0][0];

    priority_queue<pair<ll,pair<ll,ll>>> q;
    q.push({-heatLoss[0][0],{0,0}});

    vector<vector<bool>> processed(graphHeight,vector<bool>(graphWidth,false));

    vector<vector<ll>> goingDir(graphHeight, vector<ll>(graphWidth,-1));
    vector<vector<ll>> straightLength(graphHeight, vector<ll>(graphWidth,0));

    return 0;
}
