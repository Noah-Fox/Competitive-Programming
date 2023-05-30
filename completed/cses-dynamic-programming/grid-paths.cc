//https://cses.fi/problemset/task/1638/

// #include <iostream>
// #include <vector>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    int gridSize;
    cin >> gridSize;

    vector<string> grid(gridSize);

    for (int i = 0; i < gridSize; i ++){
        cin >> grid[i];
    }

    if (grid[0][0] == '*' || grid[gridSize-1][gridSize-1] == '*'){
        cout << "0\n";
        return 0;
    }
    if (gridSize == 1){
        cout << "1\n";
        return 0;
    }

    vector<ll> screen(gridSize,0);
    screen[0] = 1;

    for (int i = 1; i < 2*gridSize-1; i ++){
        vector<ll> newScreen(gridSize,0);
        int start = 0;
        int end = gridSize;
        if (i >= gridSize){
            start = 1+i-gridSize;
        }
        if (i < gridSize-1){
            end = i+1;
        }
        for (int x = start; x < end; x ++){
            if (i-x > 0 && grid[i-x-1][x] == '.'){
                newScreen[x] += screen[x];
            }
            if (x > 0 && grid[i-x][x-1] == '.'){
                newScreen[x] += screen[x-1];
            }
            if (newScreen[x] > 1000000007){
                newScreen[x] = newScreen[x] % 1000000007;
            }
        }
        screen = newScreen;
    }

    ll sum = 0;
    for (int i = 0; i < gridSize; i ++){
        sum += screen[i];
    }

    cout << sum << "\n";
    

    return 0;
}
