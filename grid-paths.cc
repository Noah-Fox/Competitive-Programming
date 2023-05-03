//https://cses.fi/problemset/task/1638

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll recurse(const vector<vector<bool>>& grid, int xOn, int yOn, vector<vector<int>>& memo){
    if (xOn == 0 && yOn == 0){
        return 1;
    }
    if (memo[xOn][yOn] > 0){
        return memo[xOn][yOn];
    }

    int count = 0;
    if (xOn > 0 && grid[xOn-1][yOn]){
        count += recurse(grid,xOn-1,yOn,memo);
    }
    if (yOn > 0 && grid[xOn][yOn-1]){
        count += recurse(grid,xOn,yOn-1,memo);
    }

    memo[xOn][yOn] = count;

    return count;
}

int main(){
    ios::sync_with_stdio(0);

    int gridSize;
    cin >> gridSize;

    vector<vector<bool>> grid(gridSize, vector<bool>(gridSize,true));
    vector<vector<int>> memo(gridSize, vector<int>(gridSize,0));

    cin.ignore();
    for (int i = 0; i < gridSize; i ++){
        for (int x = 0; x < gridSize; x ++){
            if (cin.peek() == '*'){
                grid[i][x] = false;
            }
            cin.ignore();
        }
        cin.ignore();
    }

    if (!grid[gridSize-1][gridSize-1]){
        cout << "0\n";
        return 0;
    }

    
    // cout << recurse(grid,gridSize-1,gridSize-1,memo) << "\n";
    cout << recurse(grid,gridSize-1,gridSize-1,memo) % (1000000007) << "\n";

    return 0;
}
