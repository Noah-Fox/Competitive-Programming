//https://open.kattis.com/problems/cryptotrouble

#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//return the number of valid subsets that have y 2's and up to x 1's
ll h(ll x, ll y){
    if ((y % 3) > x) return 0;
    return floor((x - (y % 3)) / 3) + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll digitAmount;
    cin >> digitAmount;

    //input digits, and record zeros and mods of 3
    ll zeros = 0, ones = 0, twos = 0, threes = 0;
    ll num;
    cin >> num;
    for (ll i = 0; i < digitAmount; i ++){
        ll digit = num % 10;
        num /= 10;

        if (digit == 0) zeros ++;
        else if (digit % 3 == 1) ones ++;
        else if (digit % 3 == 2) twos ++;
        else threes ++;
    }

    cout << zeros << " " << ones << " " << twos << " " << threes << "\n";

    //find number of subsets given only the ones and twos
    ll ans = 0;
    ans = (floor(twos/3)) * (h(ones,0) + h(ones,1) + h(ones,2));
    for (ll i = 0; i <= twos % 3; i ++){
        ans += h(ones,i);
    }
    ans --;

    cout << ans << "\n";
        
    //find the number of subsets using zeros and threes
    ans += threes + (ans * threes);
    ans *= zeros + 1;

    //output solution
    cout << ans << "\n";

    return 0;
}
