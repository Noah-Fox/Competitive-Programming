//Advent of code day 14 puzzle 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    string inLine;
    vector<string> chart;
    while (getline(cin,inLine)){
        chart.push_back(inLine);
    }

    ll chartWidth = chart[0].length();
    ll chartHeight = chart.size();

    for (ll i = 0; i < chartWidth; i ++){
        ll blockAmount = 0;
        for (ll x = chartHeight-1; x >= 0; x --){
            if (chart[x][i] == 'O'){
                blockAmount ++;
                chart[x][i] = '.';
            }
            else if (chart[x][i] == '#'){
                for (ll j = x+1; j <= x + blockAmount; j ++){
                    chart[j][i] = 'O';
                }
                blockAmount = 0;
            }
        }
        for (ll j = 0; j < blockAmount; j ++){
            chart[j][i] = 'O';
        }
    }

    ll sum = 0;
    for (ll i = 0; i < chartHeight; i ++){
        for (ll x = 0; x < chartWidth; x ++){
            if (chart[i][x] == 'O'){
                sum += chartHeight-i;
            }
        }
    }

    cout << sum << "\n";

    return 0;
}

