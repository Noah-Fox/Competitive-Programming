//Advent of code day 12 puzzle 1

//  .??..??...?##. 1,1,3

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    string inLine;
    ll sum = 0;
    
    while (getline(cin,inLine)){
        //input information
        stringstream ss(inLine);
        string springChart;
        ss >> springChart;

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

        //output spring chart and damages
        // cout << springChart << " ";
        // for (size_t i = 0; i < damages.size(); i ++){
        //     cout << damages[i] << " ";
        // }
        // cout << "\n";

        //find the number of Qs
        ll qAmount = 0;
        vector<ll> qPositions;
        for (size_t i = 0; i < springChart.length(); i ++){
            if (springChart[i] == '?'){
                qAmount ++;
                qPositions.push_back(i);
            }
        }

        //output Qs found
        // cout << qAmount << ": ";
        // for (size_t i = 0; i < qPositions.size(); i ++){
        //     cout << qPositions[i] << " ";
        // }
        // cout << "\n";

        //iterate through every possible combination
        for (ll qBits = 0; qBits < (1 << qAmount); qBits ++){
            // cout << qBits << " - ";
            string damagesUpdate = springChart;

            //assign damages
            for (ll i = 0; i < qAmount; i ++){
                if ((1 << i) & qBits){
                    damagesUpdate[qPositions[i]] = '#';
                }
                else {
                    damagesUpdate[qPositions[i]] = '.';
                }
            }

            // cout << damagesUpdate << " - ";

            //check if it fits the damages
            vector<ll> damagesFound;
            bool inDamages = false;
            ll startDamage = 0;
            for (size_t i = 0; i < damagesUpdate.length(); i ++){
                if (damagesUpdate[i] == '#'){
                    if (!inDamages){
                        inDamages = true;
                        startDamage = i;
                    }
                }
                else if (inDamages){
                    inDamages = false;
                    damagesFound.push_back(i-startDamage);
                }
            }
            if (inDamages){
                damagesFound.push_back(damagesUpdate.length()-startDamage);
            }

            // for (size_t i = 0; i < damagesFound.size(); i ++){
            //     cout << damagesFound[i] << " ";
            // }
            // cout << "\n";

            if (damagesFound.size() == damages.size()){
                bool same = true;
                for (size_t i = 0; i < damages.size(); i ++){
                    if (damages[i] != damagesFound[i]){
                        same = false;
                    }
                }
                if (same){
                    sum ++;
                }
            }
        }
    }

    cout << sum << "\n";

    return 0;
}
