//Advent of code day 6 puzzle 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){

    string s;
    cin >> s >> s;

    ll time = 0;
    ll timeInputAmount = 0;
    while (s != "Distance:"){
        time *= pow(10,s.length());
        time += stoll(s);
        cin >> s;
        timeInputAmount ++;
    }
    ll distance = 0;
    for (size_t i = 0; i < timeInputAmount; i ++){
        cin >> s;
        distance *= pow(10,s.length());
        distance += stoll(s);
    }


    ll sum = 0;
    for (ll x = 0; x <= time; x ++){
        if (x * (time-x) > distance){
            sum ++;
        }
    }
    

    cout << sum << "\n";

    return 0;
}
