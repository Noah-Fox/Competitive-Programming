//icpc pacnw div2 2020-2021

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int judgeAmount, ratingAmount;
    cin >> judgeAmount >> ratingAmount;
    int unratedAmount = judgeAmount-ratingAmount;

    double ratingSum = 0;
    for (int i = 0; i < ratingAmount; i ++){
        double a;
        cin >> a;
        ratingSum += a;
    }

    cout << (ratingSum + (-3) * unratedAmount)/judgeAmount << " ";
    cout << (ratingSum + 3 * unratedAmount)/judgeAmount << "\n";

    return 0;
}
