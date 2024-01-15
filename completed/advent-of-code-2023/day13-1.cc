//Advent of code day 13 puzzle 1

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
        for (ll x = 0; i-x >= 0 && i+x+1 < chartWidth && reflection; x ++){
            //check if columnn (i-x) is equivalent to columns (i+x+1)
            for (ll a = 0; a < chartHeight; a ++){
                if (chart[a][i-x] != chart[a][i+x+1]){
                    reflection = false;
                    break;
                }
            }
        }
        if (reflection){
            return i+1;
        }
    }

    //check for reflection across a horizontal line
    for (ll i = 0; i < chartHeight-1; i ++){
        bool reflection = true;
        for (ll x = 0; i-x >= 0 && i+x+1 < chartHeight && reflection; x ++){
            if (chart[i-x] != chart[i+x+1]){
                reflection = false;
                break;
            }
        }
        if (reflection){
            return 100 * (i+1);
        }
    }
    cout << "NO REFLECTION\n";
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
