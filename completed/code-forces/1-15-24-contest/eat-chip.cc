//https://codeforces.com/contest/1921/problem/E

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
        ll boardWidth, boardHeight, aliceX, aliceY, bobX, bobY;
        cin >> boardHeight >> boardWidth >> aliceY >> aliceX >> bobY >> bobX;

        if (aliceY >= bobY){
            cout << "Draw\n";
        }
        else {
            ll yDist = bobY - aliceY;

            if (yDist % 2 == 0){
                //bob advantage
                if (aliceX == bobX){
                    cout << "Bob\n";
                }
                else {
                    ll xDist = abs(aliceX-bobX);
                    ll xRoom = 0;
                    if (aliceX < bobX){
                        xRoom = aliceX-1;
                    }
                    else {
                        xRoom = boardWidth-aliceX;
                    }
                    ll moveAmount = yDist / 2;
                    
                    //distance between bob and alice will stay the same for xRoom rounds
                    //after xRoom rounds, the distance will close by one each round
                    if (xRoom + xDist > moveAmount){
                        cout << "Draw\n";
                    }
                    else {
                        cout << "Bob\n";
                    }
                }
            }
            else{
                //alice advantage
                if (abs(aliceX - bobX) <= 1){
                    cout << "Alice\n";
                }
                else {
                    ll xDist = abs(aliceX-bobX)-1;
                    ll xRoom = 0;
                    if (bobX < aliceX){
                        xRoom = bobX-1;
                    }
                    else {
                        xRoom = boardWidth-bobX;
                    }
                    ll moveAmount = (yDist-1) / 2;

                    if (xRoom + xDist > moveAmount){
                        cout << "Draw\n";
                    }
                    else {
                        cout << "Alice\n";
                    }
                }
            }
        }
    }

    return 0;
}
