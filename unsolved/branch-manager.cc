//icpc pacnw 22-23

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<priority_queue<ll,vector<ll>,greater<ll>>> pqv;

void removeCity(ll cityVal, pqv& cityChildren, set<ll>& removedCities){
    removedCities.insert(cityVal);
    for (int i = 0; i < cityChildren[cityVal].size(); i ++){
        removeCity(cityChildren[cityVal].top(),cityChildren,removedCities);
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll cityAmount, peopleAmount;
    cin >> cityAmount >> peopleAmount;

    // vvl cityChildren(cityAmount+1);
    pqv cityChildren(cityAmount+1);
    vector<ll> cityParents(cityAmount+1,0);

    //input the city tree
    for (int i = 0; i < cityAmount-1; i ++){
        int city1, city2;
        cin >> city1 >> city2;
        if (city1 > city2){
            swap(city1,city2);
        }
        // cityChildren[city1].push_back(city2);
        cityChildren[city1].push(city2);
        cityParents[city2] = city1;
    }

    //sort each list of children
    // for (int i = 1; i <= cityAmount; i ++){
    //     sort(cityChildren[i].begin(),cityChildren[i].end());
    // }

    ll destination;
    set<ll> removedCities;
    ll peopleRouted = 0;
    for (int i = 0; i < peopleAmount; i ++){
        cin >> destination;

        if (removedCities.count(destination)){
            cout << peopleRouted << "\n";
            return 0;
        }

        ll fromChild = destination;
        destination = cityParents[destination];
        while (destination != 0){
            while (cityChildren[destination].top() < fromChild){
                removeCity(cityChildren[destination].top(),cityChildren,removedCities);
                // cityChildren[destination].erase(cityChildren[destination].begin());
                cityChildren[destination].pop();
            }
            fromChild = destination;
            destination = cityParents[destination];
        }

        peopleRouted ++;
    }

    cout << peopleRouted << "\n";

    return 0;
}
