//https://codeforces.com/contest/1921/problem/A

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i ++){
        vector<pair<ll,ll>> corners(4);
        for (ll x = 0; x < 4; x ++){
            cin >> corners[x].first >> corners[x].second;
        }

        sort(corners.begin(),corners.end());

        cout << (corners[2].first-corners[0].first) * (corners[1].second-corners[0].second) << "\n";
    }

    return 0;
}
