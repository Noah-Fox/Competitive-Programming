//Advent of code day 11 puzzle 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    vector<pair<ll,ll> > galaxies;
    vector<bool> emptyColumns;
    ll onRow = 0;
    string inLine;

    //input map
    while (getline(cin,inLine)){
        bool empty = true;
        for (size_t i = 0; i < inLine.length(); i ++){
            if (i >= emptyColumns.size()){
                emptyColumns.push_back(true);
            }
            if (inLine[i] == '#'){
                galaxies.push_back({onRow,i});
                empty = false;
                emptyColumns[i] = false;
            }
        }
        if (empty){
            onRow ++;
        }
        onRow ++;
    }

    //move galaxies to the right for expanded empty columns
    vector<ll> expansionAmount(emptyColumns.size());
    ll expansionSum = 0;
    for (size_t i = 0; i < emptyColumns.size(); i ++){
        if (emptyColumns[i]){
            expansionSum ++;
        }
        expansionAmount[i] = expansionSum;
    }
    for (size_t i = 0; i < galaxies.size(); i ++){
        galaxies[i].second += expansionAmount[galaxies[i].second];
    }

    //find the sum of distances between every galaxy
    ll distSum = 0;
    for (size_t i = 0; i < galaxies.size(); i ++){
        for (size_t x = i+1; x < galaxies.size(); x ++){
            distSum += abs(galaxies[i].first-galaxies[x].first) + abs(galaxies[i].second-galaxies[x].second);
        }
    }

    cout << distSum << "\n";

    return 0;
}
