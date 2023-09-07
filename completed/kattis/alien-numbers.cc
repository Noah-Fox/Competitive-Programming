//https://open.kattis.com/problems/aliennumbers

#include <iostream>
#include <vector>
#include <map>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll testAmount;
    cin >> testAmount;

    //go through test cases
    for (ll i = 0; i < testAmount; i ++){
        //input
        string num, fromSys, toSys;
        cin >> num >> fromSys >> toSys;

        //find base for number systems
        ll fromBase = fromSys.length();
        ll toBase = toSys.length();
        ll digitAmount = num.length();

        //make map for initial number system
        map<char,ll> fromConversion;
        for (ll x = 0; x < fromBase; x ++){
            fromConversion[fromSys[x]] = x;
        }

        //convert to decimal
        ll decNum = 0;
        for (ll x = 0; x < digitAmount; x ++){
            decNum += fromConversion[num[x]] * pow(fromBase,digitAmount-x-1);
        }

        //convert to target number system
        string toNum = "";
        while (decNum > 0){
            toNum = toSys[decNum % toBase] + toNum;
            decNum /= toBase;
        }

        cout << "Case #" << i+1 << ": " << toNum << "\n";
    }

    return 0;
}
