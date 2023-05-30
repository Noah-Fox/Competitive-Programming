//https://cses.fi/problemset/task/1158

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> grid;

int main(){
    ios::sync_with_stdio(0);

    //input first line
    int bookAmount, budget;
    cin >> bookAmount >> budget;

    vector<ll> prices(bookAmount+1);
    vector<ll> pages(bookAmount+1);

    //input prices
    for (int i = 1; i <= bookAmount; i ++){
        cin >> prices[i];
    }

    //input pages
    for (int i = 1; i <= bookAmount; i ++){
        cin >> pages[i];
    }

    // grid maxPage(bookAmount+1,vector<ll>(budget+1,0));
    // vector<vector<ll>> maxPage();
    vector<ll> maxPage(budget+1,0);
    vector<ll> nextMaxPage(budget+1,0);
    

    for (int i = 1; i <= bookAmount; i ++){
        for (int j = 1; j <= budget; j ++){
            if (j >= prices[i]){
                nextMaxPage[j] = max(maxPage[j],maxPage[j-prices[i]]+pages[i]);
            }
        }
        maxPage = nextMaxPage;
    }

    cout << maxPage[budget] << "\n";

    return 0;
}
