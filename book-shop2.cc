//https://cses.fi/problemset/task/1158

#include <iostream>
#include <vector>
#include <map>
//#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int>> vp;

int main(){
    ios::sync_with_stdio(0);

    int bookAmount, maxPrice;
    cin >> bookAmount >> maxPrice;


    vp books(bookAmount);
    for (int i = 0; i < bookAmount; i ++){
        cin >> books[i].first;
    }
    for (int i = 0; i < bookAmount; i ++){
        cin >> books[i].second;
    }
    
    unordered_map<int,int> bookMap;

    return 0;
}
