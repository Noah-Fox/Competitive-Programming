

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll storeAmount, inventoryAmount;
    cin >> storeAmount >> inventoryAmount;

    //input inventories into a map of itemName -> set of store values
    map<string,set<ll>> items;
    ll storeValue;
    string item;
    for (ll i = 0; i < inventoryAmount; i ++){
        cin >> storeValue >> item;
        if (items.count(item) == 0){
            items[item] = {storeValue};
        }
        else {
            items[item].insert(storeValue);
        }
    }

    //input items in order
    ll itemAmount;
    cin >> itemAmount;
    stack<string> itemOrder;
    ll lowest = 0;
    for (ll i = 0; i < itemAmount; i ++){
        cin >> item;
        itemOrder.push(item);

        cout << item << ": ";
        auto it = items[item].begin();
        while (*it < lowest){
            cout << *it << " ";
            items[item].erase(it);
            if (it == items[item].end()){
                cout << "impossible\n";
                return 0;
            }
        }
        lowest = *it;
        cout << " -> " << lowest;
        cout << "\n";
    }

    //process items in reverse
    ll highest = 1000000007;
    bool multiple = false;
    while (!itemOrder.empty()){
        string onItem = itemOrder.top();
        itemOrder.pop();

        auto it = items[onItem].rbegin();
        while (*it > highest){
            items[onItem].erase(*it);
            if (it == items[onItem].rend()){
                cout << "impossible\n";
                return 0;
            }
        }
        if (items[onItem].size() > 1){
            multiple = true;
        }
        cout << onItem << ": ";
        for (auto iter = items[onItem].begin(); iter != items[onItem].end(); iter ++){
            cout << *iter << " ";
        }
        cout << "\n";
    }

    if (multiple){
        cout << "ambiguous\n";
    }
    else {
        cout << "unique\n";
    }


    return 0;
}
