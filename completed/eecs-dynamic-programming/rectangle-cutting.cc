//https://cses.fi/problemset/task/1744

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int w, h;
    cin >> w >> h;
    if (h < w){
        swap(h,w);
    }

    //create a two dimensional vector, where rects[i][j] is equal to the solution of the problem given input (i,j)
    vector<vector<int>> rects(w+1, vector<int>(h+1,0));

    for (int i = 1; i <= w; i ++){
        for (int j = i+1; j <= h; j ++){
            int gotMin = i*j;
            
            //for each element, just brute force find the minimum previous solution
            for (int a = 1; a < i; a ++){
                int w1 = min(a,j);
                int h1 = max(a,j);
                int w2 = min(i-a,j);
                int h2 = max(i-a,j);
                if (rects[w1][h1] + rects[w2][h2] + 1 < gotMin){
                    gotMin = rects[w1][h1] + rects[w2][h2] + 1;
                }
            }
            for (int a = 1; a < j; a ++){
                int w1 = min(a,i);
                int h1 = max(a,i);
                int w2 = min(j-a,i);
                int h2 = max(j-a,i);
                if (rects[w1][h1] + rects[w2][h2] + 1 < gotMin){
                    gotMin = rects[w1][h1] + rects[w2][h2] + 1;
                }
            }
            rects[i][j] = gotMin;
        }
    }

    cout << rects[w][h] << "\n";

    return 0;
}
