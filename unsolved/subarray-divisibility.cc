//https://cses.fi/problemset/task/1662

//decent algorithm, but too slow

// #include <iostream>
// #include <vector>
// #include <unordered_set>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll recurse(const vector<ll>& values, int startAt, int rangeLength, int divNum){
    if (rangeLength == 1){
        if (values[startAt] % divNum == 0){
            return 1;
        }
        else {
            return 0;
        }
    }

    int leftLength = rangeLength/2;
    int startRight = startAt + leftLength;
    int rightLength = rangeLength-leftLength;

    //vector<int> divs(divNum,0);
    unordered_multiset<ll> divs;
    ll divCount = 0;

    //cout << "Layer " << depth << " (" << values[startAt] << "-" << values[startAt+rangeLength-1] << "):\n\t";

    ll onVal = 0;
    //go through left
    for (int i = startRight-1; i >= startAt; i --){
        onVal += values[i];
        //divs[((onVal % divNum) + divNum) % divNum] ++;
        divs.insert(((onVal % divNum) + divNum) % divNum);

        //cout << "[" << (onVal % divNum) << "]";
    }
    //cout << "\n\t";

    //go through right
    onVal = 0;
    for (int i = startRight; i < startRight+rightLength; i ++){
        onVal += values[i];
        //divCount += divs[abs((divNum - (onVal % divNum)) % divNum)];
        divCount += divs.count(abs((divNum - (onVal % divNum)) % divNum));

        //cout << "[" << (divNum - (onVal % divNum)) << "]";
        /*if (divs[divNum - (onVal % divNum)] > 0){
            cout << "\t" << values[i] << ": " << divs[divNum-(onVal % divNum)] << "\n";
        }*/
    }

    //cout << "\n\t>> " << divCount << " subarrays\n";

    return divCount + recurse(values,startAt,leftLength,divNum) + recurse(values,startRight,rightLength,divNum);
}

int main(){
    ios::sync_with_stdio(0);
    int amount;
    cin >> amount;

    vector<ll> values(amount);

    for (int i = 0; i < amount; i ++){
        cin >> values[i];
    }

    cout << recurse(values,0,amount,amount) << "\n";

    return 0;
}
