//https://cses.fi/problemset/task/1194

// #include <iostream>
// #include <vector>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll h, w;
    cin >> h >> w;

    /**
     * -1 - outside map
     * 0 - wall
     * 1 - open
    */

    //input and create map
    vector<vector<ll>> gridMap(h+2,vector<ll>(w+2,-1));
    stack<pair<ll,ll>> pathNodes;
    stack<pair<ll,ll>> monsterNodes;
    vector<vector<char>> pathDirections(h+2,vector<char>(w+2,' '));
    for (ll i = 1; i <= h; i ++){
        cin.ignore();
        for (ll x = 1; x <= w; x ++){
            if (cin.peek() == '#'){
                gridMap[i][x] = 0;
            }
            else if (cin.peek() == '.'){
                gridMap[i][x] = 1;
            }
            else if (cin.peek() == 'A'){
                gridMap[i][x] = 0;
                pathNodes.push({i,x});
                pathDirections[i][x] = 'X';
            }
            else if (cin.peek() == 'M'){
                gridMap[i][x] = 0;
                monsterNodes.push({i,x});
            }
            cin.ignore();
        }
    }


    //spread paths
    while (!pathNodes.empty()){
        stack<pair<ll,ll>> nextMonsters;
        //move monsters
        while (!monsterNodes.empty()){
            ll my = monsterNodes.top().first;
            ll mx = monsterNodes.top().second;
            if (gridMap[my-1][mx] == 1){
                gridMap[my-1][mx] = 0;
                nextMonsters.push({my-1,mx});
            }
            if (gridMap[my+1][mx] == 1){
                gridMap[my+1][mx] = 0;
                nextMonsters.push({my+1,mx});
            }
            if (gridMap[my][mx-1] == 1){
                gridMap[my][mx-1] = 0;
                nextMonsters.push({my,mx-1});
            }
            if (gridMap[my][mx+1] == 1){
                gridMap[my][mx+1] = 0;
                nextMonsters.push({my,mx+1});
            }
            monsterNodes.pop();
        }
        monsterNodes = nextMonsters;

        //move paths
        stack<pair<ll,ll>> nextPaths;
        while (!pathNodes.empty()){
            ll py = pathNodes.top().first;
            ll px = pathNodes.top().second;

            char escape = ' ';
            if (py == 1){
                escape = 'U';
            }
            else if (py == h){
                escape = 'D';
            }
            else if (px == 1){
                escape = 'L';
            }
            else if (px == w){
                escape = 'R';
            }
            //output solution
            if (escape != ' '){
                stack<char> path;
                ll dist = 0;
                while (pathDirections[py][px] != 'X'){
                    path.push(pathDirections[py][px]);
                    dist ++;
                    if (pathDirections[py][px] == 'U'){
                        py ++;
                    }
                    else if (pathDirections[py][px] == 'D'){
                        py --;
                    }
                    else if (pathDirections[py][px] == 'R'){
                        px --;
                    }
                    else if (pathDirections[py][px] == 'L'){
                        px ++;
                    }
                }
                cout << "YES\n";
                cout << dist << "\n";
                while (!path.empty()){
                    cout << path.top();
                    path.pop();
                }
                cout << "\n";
                return 0;
            }

            if (gridMap[py-1][px] == 1){
                gridMap[py-1][px] = 0;
                nextPaths.push({py-1,px});
                pathDirections[py-1][px] = 'U';
            }
            if (gridMap[py+1][px] == 1){
                gridMap[py+1][px] = 0;
                nextPaths.push({py+1,px});
                pathDirections[py+1][px] = 'D';
            }
            if (gridMap[py][px-1] == 1){
                gridMap[py][px-1] = 0;
                nextPaths.push({py,px-1});
                pathDirections[py][px-1] = 'L';
            }
            if (gridMap[py][px+1] == 1){
                gridMap[py][px+1] = 0;
                nextPaths.push({py,px+1});
                pathDirections[py][px+1] = 'R';
            }
            pathNodes.pop();
        }
        pathNodes = nextPaths;
    }

    cout << "NO\n";


    return 0;
}
