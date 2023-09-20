//https://open.kattis.com/problems/whostheboss

#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,pair<ll,ll>> worker;
#define salary first
#define height second.first
#define id second.second 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll workerAmount, queryAmount;
    cin >> workerAmount >> queryAmount;

    //input workers
    vector<worker> workers(workerAmount);
    for (ll i = 0; i < workerAmount; i ++){
        cin >> workers[i].id >> workers[i].salary >> workers[i].height;
    }

    for (ll i = 0; i < workerAmount; i ++){
        cout << workers[i].id << " " << workers[i].salary << " " << workers[i].height << "\n":
    }

    return 0;
}
