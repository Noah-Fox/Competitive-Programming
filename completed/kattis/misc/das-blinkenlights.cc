//https://open.kattis.com/problems/dasblinkenlights?editsubmit=12018109

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll p, q, s;
    cin >> p >> q >> s;
    
    for (ll i = max(p,q); i <= s; i ++){
        if (i % p == 0 && i % q == 0){
            cout << "yes\n";
            return 0;
        }
    }
    
    cout << "no\n";
    
    return 0;
}
