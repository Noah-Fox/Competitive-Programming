

// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll storeAmount, inventoryAmount;
    cin >> storeAmount >> inventoryAmount;

    //input inventories
    vector<vector<string>> storeInventories(storeAmount);//for every store, record the names of the items it has
    ll storeValue;
    string item;
    for (ll i = 0; i < inventoryAmount; i ++){
        cin >> storeValue >> item;
        storeInventories[storeValue].push_back(item);
    }

    //input items in order
    ll itemAmount;
    cin >> itemAmount;
    map<string,ll> itemOrder;
    for (ll i = 0; i < itemAmount; i ++){
        cin >> item;
        itemOrder[item] = i;
    }

    //go through all item inventories in order
    vector<ll> itemPos(itemAmount,0);
    for (ll i = 0; i < storeAmount; i ++){
        priority_queue<ll> storeItems;
        for (auto it = storeInventories[i].begin(); it != storeInventories[i].end(); it ++){
            storeItems.push(-itemOrder[*it]);
        }
        while (!storeItems.empty()){
            ll onItem = -storeItems.top();
            storeItems.pop();
            if (onItem == 0){
                itemPos[0] ++;
            }
            else {
                itemPos[onItem] += itemPos[onItem-1];
            }
        }
    }

    //process solution
    for (ll i = 0; i < itemAmount; i ++){
        if (itemPos[i] == 0){
            cout << "impossible\n";
            return 0;
        }
    }
    if (itemPos[itemAmount-1] > 1){
        cout << "ambiguous\n";
    }
    else {
        cout << "unique\n";
    }

    return 0;
}
