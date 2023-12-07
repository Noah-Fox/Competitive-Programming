//Advent of code day 6 puzzle 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){

    string s;
    cin >> s >> s;

    vector<ll> time;
    while (s != "Distance:"){
        time.push_back(stoll(s));
        cin >> s;
    }
    vector<ll> distance(time.size());
    for (size_t i = 0; i < time.size(); i ++){
        cin >> distance[i];
    }

    ll product = 1;
    for (size_t i = 0; i < time.size(); i ++){
        ll sum = 0;
        for (ll x = 0; x <= time[i]; x ++){
            if (x * (time[i]-x) > distance[i]){
                sum ++;
            }
        }
        product *= sum;
    }

    cout << product << "\n";

    return 0;
}
