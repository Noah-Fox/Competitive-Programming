//Advent of code day 13 puzzle 2

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef long long ll;

ll findReflection(vector<string>& chart){
    ll chartWidth = chart[0].length();
    ll chartHeight = chart.size();
    
    //check for reflection across a vertical line
    for (ll i = 0; i < chartWidth-1; i ++){
        //check for reflection between column i and i+1
        bool reflection = true;
        bool foundSmudge = false;
        for (ll x = 0; i-x >= 0 && i+x+1 < chartWidth && reflection; x ++){
            //check if columnn (i-x) is equivalent to columns (i+x+1)
            for (ll a = 0; a < chartHeight; a ++){
                if (chart[a][i-x] != chart[a][i+x+1]){
                    if (foundSmudge){
                        reflection = false;
                        break;
                    }
                    else {
                        foundSmudge = true;
                    }
                }
            }
        }
        if (reflection && foundSmudge){
            return i+1;
        }
    }

    //check for reflection across a horizontal line
    for (ll i = 0; i < chartHeight-1; i ++){
        bool reflection = true;
        bool foundSmudge = false;
        for (ll x = 0; i-x >= 0 && i+x+1 < chartHeight && reflection; x ++){
            for (ll a = 0; a < chartWidth; a ++){
                if (chart[i-x][a] != chart[i+x+1][a]){
                    if (foundSmudge){
                        reflection = false;
                        break;
                    }
                    else {
                        foundSmudge = true;
                    }
                }
                else {
                }
            }
        }
        if (reflection && foundSmudge){
            return 100 * (i+1);
        }
    }
    
    for (ll i = 0; i < chartHeight; i ++){
        cout << chart[i] << "\n";
    }
    cout << "\n";
    return 0;
}

int main(){
    string inLine;
    vector<string> chart;
    ll sum = 0;

    while (getline(cin,inLine)){
        if (inLine.length() > 0){
            chart.push_back(inLine);
        }else {
            sum += findReflection(chart);
            chart.clear();
        }
    }
    sum += findReflection(chart);

    cout << sum << "\n";

    return 0;
}
