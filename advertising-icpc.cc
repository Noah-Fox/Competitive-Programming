//icpc pacnw 22-23 regionals

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<vector<char>> vvc;

int main(){
    ios::sync_with_stdio(0);

    int rowAmount, colAmount;
    cin >> rowAmount >> colAmount;

    vvc gridChars(rowAmount,vector<char>(colAmount));
    vvl gridNums(rowAmount,vector<ll>(colAmount,0));

    cin.ignore();
    for (int i = 0; i < rowAmount; i ++){
        for (int j = 0; j < colAmount; j ++){
            gridChars[i][j] = cin.peek();
            cin.ignore();
            if (gridChars[i][j] != '?'){
                gridNums[i][j] = 1;
            }
        }
        cin.ignore();
    }

    

    return 0;
}
