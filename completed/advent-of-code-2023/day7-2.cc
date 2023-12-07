//Advent of code day 7 puzzle 2

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main(){
    const ll handAmount = 1000;

    map<char,ll> cardVals;
    for (ll i = 1; i < 10; i ++){
        cardVals[i + '0'] = 13-i;
    }
    cardVals['T'] = 3;
    cardVals['J'] = 13;
    cardVals['Q'] = 2;
    cardVals['K'] = 1;
    cardVals['A'] = 0;

    vector<pair<ll,pair <ll,ll> > > hands(handAmount);//holds {type value, {card value, bid}}

    string hand;
    for (ll i = 0; i < handAmount; i ++){
        cin >> hand >> hands[i].second.second;
        hands[i].second.first = 0;
        for (ll x = 0; x < 5; x ++){
            hands[i].second.first = hands[i].second.first * 14 + cardVals[hand[x]];
        }

        multiset<ll> handCards;
        ll jokerAmount = 0;
        for (ll x = 0; x < 5; x ++){
            if (hand[x] != 'J'){
                handCards.insert(cardVals[hand[x]]);
            }
            else {
                jokerAmount ++;
            }
        }

        ll maxCardCount = 0;
        ll maxCard = 0;
        for (auto x = handCards.begin(); x != handCards.end(); x ++){
            if (handCards.count(*x) > maxCardCount){
                maxCardCount = handCards.count(*x);
                maxCard = *x;
            }
        }
        for (ll x = 0; x < jokerAmount; x ++){
            handCards.insert(maxCard);
        }

        ll sizeSum = 0;
        for (auto x = handCards.begin(); x != handCards.end(); x ++){
            sizeSum += handCards.count(*x);
        }


        if (sizeSum == 25){
            hands[i].first = 0;
        }
        else if (sizeSum == 17){
            hands[i].first = 1;
        }
        else if (sizeSum == 13){
            hands[i].first = 2;
        }
        else if (sizeSum == 11){
            hands[i].first = 3;
        }
        else if (sizeSum == 9){
            hands[i].first = 4;
        }
        else if (sizeSum == 7){
            hands[i].first = 5;
        }
        else {
            hands[i].first = 6;
        }

    }

    sort(hands.begin(),hands.end());

    ll sum = 0;
    for (ll i = 0; i < handAmount; i ++){
        sum += (handAmount-i) * (hands[i].second.second);
    }

    cout << sum << "\n";


    return 0;
}
