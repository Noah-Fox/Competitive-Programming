//https://cses.fi/problemset/task/1746

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main(){
    ios::sync_with_stdio(0);

    const ll MODMAX = 1000000007;

    int arrayLength, maxNum;

    cin >> arrayLength >> maxNum;

    //at each unknown value, store the amount of possible arrays for each possible number
    vector<ll> moves(maxNum+2,0);
    
    ll product = 1;

    int lastValue;
    int currentValue;

    //get first value
    cin >> lastValue;
    //if first value is zero, then any number is possible as the first
    if (lastValue == 0){
        vector<ll> nextMoves(maxNum+2,1);
        nextMoves[0] = 0;
        nextMoves[maxNum+1] = 0;
        moves = nextMoves;
    }

    //go through every number in array
    for (int i = 1; i < arrayLength; i ++){
        cin >> currentValue;
        if (currentValue == 0 && lastValue == 0){
            vector<ll> nextMoves = moves;

            for (int x = 1; x < maxNum+1; x ++){
                nextMoves[x] += moves[x-1];
                nextMoves[x] += moves[x+1];
                nextMoves[x] = nextMoves[x] % MODMAX;
            }
            moves = nextMoves;
        }
        else if (currentValue == 0 && lastValue != 0){
            vector<ll> nextMoves(maxNum+2,0);
            if (lastValue > 1){
                nextMoves[lastValue-1] = 1;
            }
            if (lastValue < maxNum){
                nextMoves[lastValue+1] = 1;
            }
            nextMoves[lastValue] = 1;
            moves = nextMoves;
        }
        else if (currentValue != 0 && lastValue == 0){
            int sum = 0;
            if (currentValue > 0){
                sum += moves[currentValue-1];
                sum = sum % MODMAX;
            }
            if (currentValue < maxNum){
                sum += moves[currentValue+1];
                sum = sum % MODMAX;
            }
            sum += moves[currentValue];
            
            sum = sum % MODMAX;
            product *= sum;
            product = product % MODMAX;            
        }
        else if (abs(currentValue-lastValue) > 1){
            cout << "0\n";
            return 0;
        }

        lastValue = currentValue;
    }

    if (lastValue == 0){
        int sum = 0;
        for (int i = 1; i < maxNum+1; i ++){
            sum += moves[i];
            sum = sum % MODMAX;
        }
        sum = sum % MODMAX;
        product *= sum;
        product = product % MODMAX;
    }


    cout << product << "\n";

    return 0;
}
