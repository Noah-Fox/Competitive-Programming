//https://open.kattis.com/problems/abandonedanimal?tab=metadata

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main(){
    ll storeAmount, inventoryAmount;
    cin >> storeAmount >> inventoryAmount;

    //input inventories
    vector<pair<ll,string>> inventories(inventoryAmount);
    for (ll i = 0; i < inventoryAmount; i ++){
        cin >> inventories[i].first >> inventories[i].second;
    }

    //input items
    ll itemAmount;
    cin >> itemAmount;
    map<string,ll> itemOrder;//for each item, stores its position in order
    string item;
    for (ll i = 0; i < itemAmount; i ++){
        cin >> item;
        itemOrder[item] = i;
    }

    //store everything in a 2D vector
    vector<vector<ll>> itemStores(itemAmount);//for item at position i, stores a vector of stores that it can be found in
    for (ll i = 0; i < inventoryAmount; i ++){
        item = inventories[i].second;
        ll index = itemOrder[item];
        itemStores[index].push_back(inventories[i].first);
    }

    //sort every itemStores vector
    for (ll i = 0; i < itemAmount; i ++){
        sort(itemStores[i].begin(), itemStores[i].end());
    }

    //process forward
    vector<ll> itemLows(itemAmount);//lowest valid store value for each item
    ll highestLow = 0;
    for (ll i = 0; i < itemAmount; i ++){
        auto forwardIt = itemStores[i].begin();
        //find first valid value
        while (forwardIt != itemStores[i].end() && *forwardIt < highestLow){
            forwardIt ++;
        }
        //output impossible if there are no valid values
        if (forwardIt == itemStores[i].end()){
            cout << "impossible\n";
            return 0;
        }
        itemLows[i] = *forwardIt;
        highestLow = *forwardIt;
    }

    //process backward
    // vector<ll> itemHighs(itemAmount);//highest valid store value for each item
    ll lowestHigh = 1000007;
    bool multiple = false;
    for (ll i = itemAmount-1; i >= 0; i --){
        auto backIt = itemStores[i].rbegin();
        //find highest valid value
        while (backIt != itemStores[i].rend() && *backIt > lowestHigh){
            backIt ++;
        }
        //output impossible if there are no valid values
        if (backIt == itemStores[i].rend() || *backIt < itemLows[i]){
            cout << "impossible\n";
            return 0;
        }
        lowestHigh = *backIt;
        //find the number of valid values
        ll validItemCount = 0;
        while (backIt != itemStores[i].rend() && *backIt >= itemLows[i]){
            validItemCount ++;
            backIt ++;
        }
        if (validItemCount > 1){
            multiple = true;
        }
    }

    //output solution
    if (multiple){
        cout << "ambiguous\n";
    }
    else {
        cout << "unique\n";
    }

    return 0;
}
