//Advent of code day 4 puzzle 1

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main(){
    const ll cardAmount = 219;
    const ll winNumberAmount = 10;
    const ll inputNumberAmount = 25;

    string s;
    ll num;
    vector<ll> copyAmount(cardAmount,1);

    for (ll i = 0; i < cardAmount; i ++){
        cin >> s >> s;

        unordered_set<ll> winNums;
        for (ll x = 0; x < winNumberAmount; x ++){
            cin >> num;
            winNums.insert(num);
        }

        cin >> s;

        ll count = 0;
        for (ll x = 0; x < inputNumberAmount; x ++){
            cin >> num;
            if (winNums.count(num) > 0){
                count ++;
            }
        }


        for (ll x = i+1; x < min(i+count+1,cardAmount); x ++){
            copyAmount[x] += copyAmount[i];
        }
    }

    ll sum = 0;
    for (ll i = 0; i < cardAmount; i ++){
        sum += copyAmount[i];
    }
    cout << sum << "\n";


    return 0;
}
