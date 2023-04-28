//https://cses.fi/problemset/task/1141

using namespace std;

// #include <iostream>
// #include <map>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    map<int,int> lastLocations;
    int songAmount;
    int onSong;
    int rangeCount = 0;
    int highestRange = 0;
    cin >> songAmount;

    for (int i = 0; i < songAmount; i ++){
        cin >> onSong;
        
        if (lastLocations.count(onSong) && (i-lastLocations[onSong]) <= rangeCount){
            rangeCount = (i-lastLocations[onSong]);
        }
        else {
            rangeCount ++;
        }

        if (rangeCount > highestRange){
            highestRange = rangeCount;
        }
        
        lastLocations[onSong] = i;
    }
    cout << highestRange << "\n";;

    return 0;
}
