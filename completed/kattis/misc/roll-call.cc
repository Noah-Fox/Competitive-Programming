//https://open.kattis.com/problems/rollcall

// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //input
    string firstName, lastName;
    vector<pair<string,string>> names;
    unordered_map<string,ll> firstNameAmount;
    while (cin >> firstName){
        cin >> lastName;

        names.push_back({lastName,firstName});
        if (firstNameAmount.count(firstName) == 0){
            firstNameAmount[firstName] = 1;
        }
        else {
            firstNameAmount[firstName] ++;
        }
    }

    sort(names.begin(),names.end());

    for (auto it = names.begin(); it != names.end(); it ++){
        cout << (it -> second);
        if (firstNameAmount[it -> second] > 1){
            cout << " " << (it -> first);
        }
        cout << "\n";
    }
    

    return 0;
}
