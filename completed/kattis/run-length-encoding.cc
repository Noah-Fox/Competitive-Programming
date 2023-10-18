//https://open.kattis.com/problems/runlengthencodingrun

// #include <iostream>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char op;
    string message;
    cin >> op >> message;

    //decode 
    if (op == 'D'){
        string solution = "";
        for (ll i = 0; i < message.length(); i += 2){
            for (ll x = 0; x < message[i+1]-'0'; x ++){
                solution += message[i];
            }
        }
        cout << solution << "\n";
    }
    //encode
    else {
        string solution = "";
        char onChar = message[0];
        ll count = '1';
        for (ll i = 1; i < message.length(); i ++){
            if (message[i] == onChar){
                count ++;
            }
            else {
                solution += onChar;
                solution += count;
                count = '1';
                onChar = message[i];
            }
        }
        solution += onChar;
        solution += count;
        cout << solution << "\n";
    }

    return 0;
}
