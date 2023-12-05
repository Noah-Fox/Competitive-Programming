//Advent of code day 3 puzzle 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

bool checkNum(vector<string>& machine, ll rowSize, ll startNum, ll endNum, ll onRow, vector<vector<ll>>& gearRatios, vector<vector<ll>>& gearCount, ll numVal){
    bool sol = false;
    
    if (startNum > 0 && machine[onRow][startNum-1] != '.'){
        sol = true;

        if (machine[onRow][startNum-1] == '*'){
            gearRatios[onRow][startNum-1] *= numVal;
            gearCount[onRow][startNum-1] ++;
            // cout << numVal << ": " << onRow << " " << startNum-1 << " left\n";
        }
    }
    if (endNum < rowSize-1 && machine[onRow][endNum+1] != '.'){
        sol = true;

        if (machine[onRow][endNum+1] == '*'){
            gearRatios[onRow][endNum+1] *= numVal;
            gearCount[onRow][endNum+1] ++;
            // cout << numVal << ": " << onRow << " " << endNum+1 << " right\n";
        }
    }

    for (ll i = max(startNum-1,ll(0)); i <= min(rowSize-1,endNum+1); i ++){
        if (machine[onRow-1][i] != '.' && !isdigit(machine[onRow-1][i])){
            sol = true;

            if (machine[onRow-1][i] == '*'){
                gearRatios[onRow-1][i] *= numVal;
                gearCount[onRow-1][i] ++;
                // cout << numVal << ": " << onRow-1 << " " << i << " up\n";
            }
        }
        if (machine[onRow+1][i] != '.' && !isdigit(machine[onRow+1][i])){
            sol = true;

            if (machine[onRow+1][i] == '*'){
                gearRatios[onRow+1][i] *= numVal;
                gearCount[onRow+1][i] ++;
                // cout << numVal << ": " << onRow+1 << " " << i << " down\n";
            }
        }
    }

    return sol;
}

int main(){

    const ll rowAmount = 140;
    const ll rowSize = 140;

    vector<string> machine(rowAmount+2);
    machine[0] = "............................................................................................................................................";
    machine[rowAmount+1] = "............................................................................................................................................";
    // machine[0] = "..........";
    // machine[rowAmount+1] = "..........";

    vector<vector<ll>> gearRatios(rowAmount+2,vector<ll>(rowSize,1));
    vector<vector<ll>> gearCount(rowAmount+2,vector<ll>(rowSize,0));

    for (ll i = 1; i <= rowAmount; i ++){
        cin >> machine[i];
    }

    for (ll i = 1; i <= rowAmount; i ++){
        bool onNum = false;
        ll startNum = -1;
        ll endNum = -1;
        ll numVal = 0;
        for (ll x = 0; x < rowSize; x ++){
            if (isdigit(machine[i][x])){
                numVal = 10*numVal + (machine[i][x]-'0');
                if (!onNum){
                    onNum = true;
                    startNum = x;
                }
            }
            else if (!isdigit(machine[i][x]) && onNum){
                onNum = false;
                endNum = x-1;

                checkNum(machine,rowSize,startNum,endNum,i,gearRatios,gearCount,numVal);

                numVal = 0;
            }
        }
        if (onNum){
            checkNum(machine,rowSize,startNum,rowSize-1,i,gearRatios,gearCount,numVal);
        }
    }

    ll sum = 0;

    for (ll i = 0; i <= rowAmount+1; i ++){
        for (ll x = 0; x < rowSize; x ++){
            if (gearCount[i][x] == 2){
                sum += gearRatios[i][x];
            }
            // cout << gearCount[i][x] << " ";
        }
        // cout << "\n";
    }

    cout << sum << "\n";

    return 0;
}
