//Advent of code day 2 puzzle 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main(){

    string str1;
    string str2;
    ll num;
    ll sum = 0;

    for (ll i = 1; i <= 100; i ++){
        cin >> str1 >> str2;


        bool validGame = true;

        while (!isalpha(str2[str2.length()-1])){
            cin >> num >> str2;
            if (str2 == "red," || str2 == "red;" || str2 == "red"){
                if (num > 12){
                    validGame = false;
                }
            }
            else if (str2 == "green," || str2 == "green;" || str2 == "green"){
                if (num > 13){
                    validGame = false;
                }
            }
            else if (str2 == "blue," || str2 == "blue;" || str2 == "blue"){
                if (num > 14){
                    validGame = false;
                }
            }
            else {
                validGame = false;
            }
        }

        if (validGame){
            sum += i;
        }

    }

    cout << sum << "\n";

    return 0;
}
