//https://codeforces.com/contest/1921/problem/B

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
        ll boxAmount;
        cin >> boxAmount;
        string start, end;
        cin >> start >> end;

        ll addCatAmount = 0;
        ll removeCatAmount = 0;
        for (ll x = 0; x < boxAmount; x ++){
            if (start[x] == '0' && end[x] == '1'){
                addCatAmount ++;
            }
            else if (start[x] == '1' && end[x] == '0'){
                removeCatAmount ++;
            }
        }

        cout << max(addCatAmount, removeCatAmount) << "\n";
    }

    return 0;
}
