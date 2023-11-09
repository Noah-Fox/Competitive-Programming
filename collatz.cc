//https://open.kattis.com/problems/coltype

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string pattern;
    cin >> pattern;

    if (pattern[pattern.length()-1] != 'O'){
        cout << "INVALID\n";
        return 0;
    }

    ll twoPow = 1;
    // ll minAns = -1;
    for (ll i = 2; i <= 47; i ++){
        twoPow *= 2;
        ll onVal = twoPow;
        bool works = true;
        char lastChar = 'E';
        for (ll x = pattern.length()-1; x >= 0; x --){
            if (pattern[x] == 'O'){
                if (lastChar == 'O' || (onVal-1) % 3 != 0){
                    works = false;
                    break;
                }
                else {
                    onVal = (onVal-1)/3;
                    lastChar = 'O';
                    if (onVal % 2 == 0){
                        works = false;
                        break;
                    }
                }
            }
            else {
                lastChar = 'E';
                onVal *= 2;
                if (onVal < 0){
                    works = false;
                    break;
                }
            }
        }
        // if (works && (minAns == -1 || onVal < minAns)){
        //     minAns = onVal;
        // }
        if (works){
            cout << onVal << "\n";
            return 0;
        }
    }

    cout << "INVALID\n";
    // if (minAns == -1){
    //     cout << "INVALID\n";
    // }
    // else {
    //     cout << minAns << "\n";
    // }

    return 0;
}
