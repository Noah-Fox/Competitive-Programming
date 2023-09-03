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

    //store everything in a 2D vector - for each store, all of its items in order
    vector<vector<ll>> items(storeAmount);
    for (ll i = 0; i < inventoryAmount; i ++){
        items[inventories[i].first].push_back(itemOrder[inventories[i].second]);
    }

    //sort each store's inventory
    for (ll i = 0; i < storeAmount; i ++){
        sort(items[i].begin(),items[i].end());
    }

    //process each item
    vector<ll> counts(itemAmount,0);
    for (ll i = 0; i < storeAmount; i ++){
        for (auto it = items[i].begin(); it != items[i].end(); it ++){
            if (*it == 0){
                counts[0] ++;
            }
            else {
                counts[*it] += counts[*it-1];
            }
        }
    }

    //output solution
    if (counts[itemAmount-1] == 0){
        cout << "impossible\n";
    }
    else if (counts[itemAmount-1] == 1){
        cout << "unique\n";
    }
    else {
        cout << "ambiguous\n";
    }

    return 0;
}
