//https://open.kattis.com/problems/parking

#include <iostream>

using namespace std;

int main(){

    int prices[4];
    prices[0] = 0;
    cin >> prices[1] >> prices[2] >> prices[3];
    prices[2] *= 2;
    prices[3] *= 3;

    int amountParked[101] = {0};
    for (int i = 0; i < 3; i ++){
        int start, stop;
        cin >> start >> stop;
        for (int x = start; x < stop; x ++){
            amountParked[x] ++;
        }
    }

    int sum = 0;
    for (int i = 1; i <= 100; i ++){
        sum += prices[amountParked[i]];
    }
    cout << sum << "\n";

    return 0;
}
