//Advent of code day 15 puzzle 1

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    string inStr;
    getline(cin,inStr);
    stringstream ss(inStr+',');
    vector<string> seq;
    while (getline(ss,inStr,',')){
        seq.push_back(inStr);
    }
    
    ll sum = 0;
    for (size_t i = 0; i < seq.size(); i ++){
        ll curVal = 0;
        for (size_t x = 0; x < seq[i].length(); x ++){
            curVal += seq[i][x];
            curVal *= 17;
            curVal %= 256;
        }
        sum += curVal;
    }

    cout << sum << "\n";

    return 0;
}
