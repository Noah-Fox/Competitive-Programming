//https://open.kattis.com/problems/isbnconversion

// #include <iostream>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i ++){
        string code;
        cin >> code;

        //parse digits
        bool valid = true;
        vector<ll> digits(10);
        ll onDigit = 0;
        bool wasHyphen = false;
        ll hyphenCount = 0;
        queue<ll> hyphenPositions;
        for (ll x = 0; x < code.length(); x ++){
            if (onDigit >= 10){
                valid = false;
                continue;
            }
            if (code[x] == '-'){
                if (x == 0 || x == code.length()-1 || wasHyphen){
                    valid = false;
                    // break;
                }
                if (hyphenCount == 2 && onDigit != 9){
                    valid = false;
                }
                hyphenCount ++;
                wasHyphen = true;
                hyphenPositions.push(onDigit);
            }
            else if (code[x] == 'X'){
                if (x != code.length()-1 || onDigit != 9){
                    valid = false;
                    // break;
                }
                digits[onDigit] = 10;
                onDigit ++;
                wasHyphen = false;
            }
            else {
                digits[onDigit] = code[x] - '0';
                onDigit ++;
                wasHyphen = false;
            }
        }

        if (!valid){
            cout << "invalid\n";
            continue;
        }

        //verify the checksum
        ll sum = 0;
        for (ll x = 0; x < 10; x ++){
            sum += (10-x) * digits[x];
        }


        if (sum % 11 != 0){
            cout << "invalid\n";
            continue;
        }

        //convert to ISBN-13
        sum = 9+3*7+8;
        vector<ll> outputDigits(10);
        for (ll x = 0; x < 9; x ++){
            if (x % 2 == 0){
                sum += 3*digits[x];
            }
            else {
                sum += digits[x];
            }
            outputDigits[x] = digits[x];
        }
        outputDigits[9] = 10 - (sum % 10);

        cout << "978-";
        for (ll x = 0; x < 10; x ++){
            if (!hyphenPositions.empty() && x == hyphenPositions.front()){
                cout << "-";
                hyphenPositions.pop();
            }
            cout << outputDigits[x];
        }
        cout << "\n";
    }

    return 0;
}

