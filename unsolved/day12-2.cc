//Advent of code day 12 puzzle 2

//  ?????.??.???.??????.??.???.??????.??.???.??????.??.???.??????.??.???. 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

ll damageCombos(string springChart, ll onSpring, vector<ll>& damages, ll onDamage){
    if (onDamage == damages.size()){
        // for (ll j = 0; j < onDamage; j ++){
        //     cout << ' ';
        // }
        // cout << "base case - ";
        for (size_t i = onSpring; i < springChart.size(); i ++){
            if (springChart[i] == '#'){
                // cout << " damage left\n";
                return 0;
            }
        }
        // cout << "valid\n";
        return 1;
    }

    // for (ll j = 0; j < onDamage; j ++){
    //     cout << ' ';
    // }
    // cout << "On damage " << onDamage << ": " << damages[onDamage] << ", spring: " << onSpring << "\n";

    ll sum = 0;
    for (size_t i = onSpring; i <= springChart.length()-damages[onDamage]; i ++){
        // for (ll j = 0; j < onDamage; j ++){
        //     cout << ' ';
        // }
        // cout << damages[onDamage] << " at " << i << " - ";

        //check if theres a damage before the start point
        for (size_t x = onSpring; x < i; x ++){
            if (springChart[x] == '#'){
                // cout << "damage before\n";
                return sum;
            }
        }

        //check if theres nondamage within the zone
        bool validZone = true;
        for (size_t x = i; x < i+damages[onDamage]; x ++){
            if (springChart[x] == '.'){
                validZone = false;
            }
        }
        if (springChart[i+damages[onDamage]] == '#'){
            validZone = false;
        }

        if (validZone){
            // cout << "recurse\n";
            ll recurseVal = damageCombos(springChart, i+damages[onDamage]+1, damages, onDamage+1);
            if (recurseVal == 0){
                return sum;
            }
            sum += recurseVal;
        }
        // else {
        //     cout << "invalid zone\n";
        // }
    }

    return sum;
}

int main(){
    string inLine;
    ll sum = 0;
    
    ll onLine = 0;
    while (getline(cin,inLine)){
        cout << onLine++ << "\n";
        //input information
        stringstream ss(inLine);
        string springChart;
        ss >> springChart;
        springChart = springChart + '?' + springChart + '?' + springChart + '?' + springChart + '?' + springChart;

        string damagesString;
        ss >> damagesString;

        vector<ll> damages;
        ll onComma = 0;
        ll nextComma = damagesString.find_first_of(',');
        while (nextComma != string::npos){
            damages.push_back(stoi(damagesString.substr(onComma, nextComma-onComma)));
            onComma = nextComma+1;
            nextComma = damagesString.find_first_of(',',onComma);
        }
        damages.push_back(stoi(damagesString.substr(onComma)));

        //make damages five times itself
        ll damageAmount = damages.size();
        for (ll i = 0; i < 4; i ++){
            for (ll x = 0; x < damageAmount; x ++){
                damages.push_back(damages[x]);
            }
        }

        // cout << springChart << " ";
        // for (size_t i = 0; i < damages.size(); i ++){
        //     cout << damages[i] << " ";
        // }
        // cout << "\n";

        ll damageComboAmount = damageCombos(springChart, 0, damages, 0);
        // cout << damageComboAmount << "\n";
        sum += damageComboAmount;
    }

    cout << sum << "\n";

    return 0;
}
