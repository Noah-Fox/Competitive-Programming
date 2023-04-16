//https://open.kattis.com/problems/armystrengtheasy

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int testAmount;
    cin >> testAmount;

    for (int i = 0; i < testAmount; i ++){
        int gAmount, mAmount;
        cin >> gAmount >> mAmount;

        priority_queue<int,vector<int>,greater<int> > gArmy;
        priority_queue<int,vector<int>,greater<int> > mArmy;

        int s;
        for (int x = 0; x < gAmount; x ++){
            cin >> s;
            gArmy.push(s);
        }
        for (int x = 0; x < mAmount; x ++){
            cin >> s;
            mArmy.push(s);
        }

        while (!gArmy.empty() && !mArmy.empty()){
            if (gArmy.top() < mArmy.top()){
                gArmy.pop();
            }
            else{
                mArmy.pop();
            }
        }

        if (gArmy.empty()){
            cout << "MechaGodzilla\n";
        }
        else {
            cout << "Godzilla\n";
        }
    }
    return 0;
}
