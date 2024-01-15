//https://codeforces.com/contest/1921/problem/D

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll testCases;
    cin >> testCases;
    
    for (ll i = 0; i < testCases; i ++){
        ll n, m;
        cin >> n >> m;

        vector<ll> aArray(n);
        vector<ll> bArray(m);
        vector<ll> cArray(n);

        for (ll x = 0; x < n; x ++){
            cin >> aArray[x];
        }
        for (ll x = 0; x < m; x ++){
            cin >> bArray[x];
        }

        sort(aArray.begin(), aArray.end());
        sort(bArray.begin(), bArray.end());

        ll aMin = 0, aMax = n-1;
        ll bMin = 0, bMax = m-1;

        while (aMin <= aMax){
            if (abs(aArray[aMin]-bArray[bMax]) > abs(aArray[aMax]-bArray[bMin])){
                cArray[aMin] = bArray[bMax];
                aMin ++;
                bMax --;
            }
            else {
                cArray[aMax] = bArray[bMin];
                aMax --;
                bMin ++;
            }
        }

        ll sum = 0;
        for (ll x = 0; x < n; x ++){
            sum += abs(aArray[x]-cArray[x]);
        }
        cout << sum << "\n";
    }

    return 0;
}
