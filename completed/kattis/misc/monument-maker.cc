//https://open.kattis.com/problems/monumentmaker

// #include <iostream>
// #include <vector>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll lineAmount, originalWidth, nextWidth;
    cin >> lineAmount >> originalWidth >> nextWidth;

    ll onLine = 1, onChar = 0, onWordChar = 0;
    string line;
    for (ll i = 0; i < lineAmount; i ++){
        cin >> line;
        ll lineWidth = line.length();

        ll dir = 1;
        ll start = 0;
        if (i % 2 == 1){
            dir = -1;
            start = lineWidth - 1;
        }

        for (ll x = start; x >= 0 && x < lineWidth; x += dir){
            if (line[x] == ' '){
                break;
            }
            if (line[x] == '.'){
                onChar ++;
                onWordChar = 0;
            }
            else {
                onChar ++;
                onWordChar ++;
            }
            if (onChar > nextWidth){
                onChar = onWordChar;
                onLine ++;
            }
        }
        
    }

    cout << onLine << "\n";

    return 0;
}
