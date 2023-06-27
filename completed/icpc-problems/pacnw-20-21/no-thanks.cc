//icpc pacnw 20-21 regionals div2

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll cardAmount;
    cin >> cardAmount;

    vector<bool> deck(90001,false);

    for (int i = 0; i < cardAmount; i ++){
        int onCard;
        cin >> onCard;
        deck[onCard] = true;
    }


    ll score = 0;
    ll countCard = 0;
    for (ll i = 90000; i >= 0; i --){
        if (deck[i]){
            countCard = i;
        }
        else if (countCard > 0){
            score += countCard;
            countCard = 0;
        }
    }

    cout << score << "\n";


    return 0;
}
