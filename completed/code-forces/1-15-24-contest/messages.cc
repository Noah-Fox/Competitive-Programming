//https://codeforces.com/contest/1921/problem/C

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll testAmount;
    cin >> testAmount;

    for (ll i = 0; i < testAmount; i ++){
        ll messageAmount, battery, stepCost, jumpCost;
        cin >> messageAmount >> battery >> stepCost >> jumpCost;

        ll lastMessage = 0;
        vector<ll> messages(messageAmount);
        for (ll x = 0; x < messageAmount; x ++){
            cin >> messages[x];
        }
        for (ll x = 0; x < messageAmount; x ++){
            ll nextMessage = messages[x];

            if ((nextMessage-lastMessage) * stepCost < jumpCost){
                battery -= (nextMessage-lastMessage)*stepCost;
            }
            else {
                battery -= jumpCost;
            }


            if (battery <= 0){
                break;
            }

            lastMessage = nextMessage;
        }
        if (battery > 0){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
