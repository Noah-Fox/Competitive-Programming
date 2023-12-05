//Advent of code day 2 puzzle 2

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

        ll redMax = 0;
        ll greenMax = 0;
        ll blueMax = 0;



        while (!isalpha(str2[str2.length()-1])){
            cin >> num >> str2;
            if (str2 == "red," || str2 == "red;" || str2 == "red"){
                redMax = max(redMax,num);
            }
            else if (str2 == "green," || str2 == "green;" || str2 == "green"){
                greenMax = max(greenMax,num);
            }
            else if (str2 == "blue," || str2 == "blue;" || str2 == "blue"){
                blueMax = max(blueMax,num);
            }
        }

        sum += redMax * greenMax * blueMax;

    }

    cout << sum << "\n";

    return 0;
}
