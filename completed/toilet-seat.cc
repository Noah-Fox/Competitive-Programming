//https://open.kattis.com/problems/toilet?editsubmit=10734119

#include <iostream>

using namespace std;

int main(){
    char pos1, pos2, pos3;
    int sum1, sum2, sum3;
    sum1 = sum2 = sum3 = 0;
    char in;
    cin >> in;
    pos1 = pos2 = pos3 = in;
    
    while (cin.peek() != '\n'){
        cin >> in;

        if (pos1 != in){
            sum1 ++;
        }
        if (in == 'D'){
            sum1 ++;
        }
        if (pos2 != in){
            sum2 ++;
        }
        if (in == 'U'){
            sum2 ++;
        }
        if (pos3 != in){
            sum3 ++;
        }
        pos1 = 'U';
        pos2 = 'D';
        pos3 = in;
    }
    cout << sum1 << '\n' << sum2 << '\n' << sum3 << '\n';
}
