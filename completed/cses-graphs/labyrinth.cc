//https://cses.fi/problemset/task/1193

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
    bool isFloor = false;
    char cameFrom = 'X';
};

int main(){
    ios::sync_with_stdio(0);

    ll height, width;
    cin >> height >> width;

    vector<vector<Node>> gridMap(height+2,vector<Node>(width+2));

    pair<ll,ll> start, end;

    for (ll i = 1; i <= height; i ++){
        cin.ignore();
        for (ll x = 1; x <= width; x ++){
            if (cin.peek() != '#'){
                gridMap[i][x].isFloor = true;
                if (cin.peek() == 'A'){
                    start = {i,x};
                }
                else if (cin.peek() == 'B'){
                    end = {i,x};
                }
            }
            cin.ignore();
        }
    }

    stack<pair<ll,ll>> spreadMap;
    spreadMap.push(start);
    while (!spreadMap.empty()){
        stack<pair<ll,ll>> nextSpread;
        while (!spreadMap.empty()){
            pair<ll,ll> onNode = spreadMap.top();
            spreadMap.pop();

            if (onNode == end){
                //output solution

                stack<char> path;
                ll pathLength = 0;
                while (onNode != start){
                    path.push(gridMap[onNode.first][onNode.second].cameFrom);
                    pathLength ++;
                    if (path.top() == 'U'){
                        onNode.first ++;
                    }
                    else if (path.top() == 'D'){
                        onNode.first --;
                    }
                    else if (path.top() == 'R'){
                        onNode.second --;
                    }
                    else {
                        onNode.second ++;
                    }
                }
                
                cout << "YES\n" << pathLength << "\n";
                while (!path.empty()){
                    cout << path.top();
                    path.pop();
                }
                cout << "\n";
                return 0;
            }

            if (gridMap[onNode.first-1][onNode.second].isFloor){
                nextSpread.push({onNode.first-1,onNode.second});
                gridMap[onNode.first-1][onNode.second].isFloor = false;
                gridMap[onNode.first-1][onNode.second].cameFrom = 'U';
            }
            if (gridMap[onNode.first+1][onNode.second].isFloor){
                nextSpread.push({onNode.first+1,onNode.second});
                gridMap[onNode.first+1][onNode.second].isFloor = false;
                gridMap[onNode.first+1][onNode.second].cameFrom = 'D';
            }
            if (gridMap[onNode.first][onNode.second-1].isFloor){
                nextSpread.push({onNode.first,onNode.second-1});
                gridMap[onNode.first][onNode.second-1].isFloor = false;
                gridMap[onNode.first][onNode.second-1].cameFrom = 'L';
            }
            if (gridMap[onNode.first][onNode.second+1].isFloor){
                nextSpread.push({onNode.first,onNode.second+1});
                gridMap[onNode.first][onNode.second+1].isFloor = false;
                gridMap[onNode.first][onNode.second+1].cameFrom = 'R';
            }
        }
        spreadMap = nextSpread;
    }

    cout << "NO\n";

    return 0;
}
