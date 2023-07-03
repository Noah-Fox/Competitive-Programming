//icpc pacnw 2020-2021 div 2

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int numAmount;
    cin >> numAmount;

    cin.ignore();
    for (int i = 1; i <= numAmount; i ++){
        if (i < 10){
            if (cin.peek() != i + '0'){
                cout << i << "\n";
                return 0;
            }
            else {
                cin.ignore();
            }
        }
        else if (i < 100){
            if (cin.peek() != (i/10) + '0'){
                cout << i << "\n";
                return 0;
            }
            else {
                cin.ignore();
            }
            if (cin.peek() != (i % 10) + '0'){
                cout << i << "\n";
                return 0;
            }
            else {
                cin.ignore();
            }
        }
        else {
            cout << 100 << "\n";
            return 0;
        }
    }

    return 0;
}
