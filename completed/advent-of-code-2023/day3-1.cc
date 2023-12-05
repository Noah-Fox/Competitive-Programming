//Advent of code day 3 puzzle 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

bool checkNum(vector<string>& machine, ll rowSize, ll startNum, ll endNum, ll onRow){
    if (startNum > 0 && machine[onRow][startNum-1] != '.'){
        return true;
    }
    if (endNum < rowSize-1 && machine[onRow][endNum+1] != '.'){
        return true;
    }

    for (ll i = max(startNum-1,ll(0)); i <= min(rowSize-1,endNum+1); i ++){
        if (machine[onRow-1][i] != '.' && !isdigit(machine[onRow-1][i])){
            return true;
        }
        if (machine[onRow+1][i] != '.' && !isdigit(machine[onRow+1][i])){
            return true;
        }
    }

    return false;
}

int main(){

    const ll rowAmount = 140;
    const ll rowSize = 140;

    vector<string> machine(rowAmount+2);
    machine[0] = "............................................................................................................................................";
    machine[rowAmount+1] = "............................................................................................................................................";

    for (ll i = 1; i <= rowAmount; i ++){
        cin >> machine[i];
    }

    ll sum = 0;

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

                if (checkNum(machine,rowSize,startNum,endNum,i)){
                    sum += numVal;
                }
                numVal = 0;
            }
        }
        if (onNum && checkNum(machine,rowSize,startNum,rowSize-1,i)){
            sum += numVal;
        }
    }

    cout << sum << "\n";

    return 0;
}
