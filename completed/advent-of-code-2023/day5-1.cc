//Advent of code Day 5 Puzzle 1

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    
    vector<ll> srcVals;
    string str1;

    //input seed line
    cin >> str1 >> str1;
    while (str1 != "seed-to-soil"){
        srcVals.push_back(stoll(str1));
        cin >> str1;
    }

    for (ll i = 0; i < 7; i ++){
        vector<ll> destVals = srcVals;

        cin >> str1 >> str1;
        ll srcStart, destStart, rangeLength;

        while (isdigit(str1[0])){
            destStart = stoll(str1);
            cin >> srcStart >> rangeLength;

            for (size_t x = 0; x < srcVals.size(); x ++){
                if (srcVals[x]-srcStart < rangeLength && srcVals[x] >= srcStart){
                    destVals[x] = destStart + (srcVals[x]-srcStart);
                    srcVals[x] = -1;
                }
            }

            cin >> str1;
        }

        srcVals = destVals;
    }

    ll minVal = srcVals[0];
    for (size_t i = 1; i < srcVals.size(); i ++){
        minVal = min(minVal,srcVals[i]);
    }
    cout << minVal << "\n";


    return 0;
}
