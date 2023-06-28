//icpc pacnw 22-23 regionals

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;



int main(){
    ios::sync_with_stdio(0);

    int rowAmount, colAmount;
    cin >> rowAmount >> colAmount;

    vvc gridChars(rowAmount,vector<char>(colAmount));
    vvb canMakeAd(rowAmount,vector<bool>(colAmount,false));
    vvb isMakingAd(rowAmount,vector<bool>(colAmount,false));

    cin.ignore();
    for (int i = 0; i < rowAmount; i ++){
        for (int j = 0; j < colAmount; j ++){
            gridChars[i][j] = cin.peek();
            cin.ignore();
        }
        cin.ignore();
    }

    for (int i = 0; i < rowAmount-1; i ++){
        for (int j = 0; j < colAmount-1; j ++){
            char a1 = gridChars[i][j];
            char a2 = gridChars[i][j+1];
            char a3 = gridChars[i+1][j];
            char a4 = gridChars[i+1][j+1];
            if ((a1 == 'I' || a1 == '?') && (a2 == 'C' || a2 == '?') && (a3 == 'P' || a3 == '?') && (a4 == 'C' || a4 == '?')){
                canMakeAd[i][j] = true;
            }
        }
    }



    return 0;
}
