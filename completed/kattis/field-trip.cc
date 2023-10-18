//https://open.kattis.com/contests/w9i5jp/problems/classfieldtrip

// #include <iostream>
// #include <vector>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    ll aLength = a.length();
    ll bLength = b.length();

    ll onA = 0;
    ll onB = 0;
    string solution = "";

    while (onA < aLength && onB < bLength){
        if (a[onA] < b[onB]){
            solution += a[onA];
            onA ++;
        }
        else {
            solution += b[onB];
            onB ++;
        }
    }
    while (onA < aLength){
        solution += a[onA];
        onA ++;
    }
    while (onB < bLength){
        solution += b[onB];
        onB ++;
    }

    cout << solution << "\n";

    return 0;
}
