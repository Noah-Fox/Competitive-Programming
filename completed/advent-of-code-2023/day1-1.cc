//Advent of Code 2023 Day 1 Puzzle 1

#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll sum = 0;

    string inputLine = "";
    cin >> inputLine;
    while (inputLine != ""){
        ll onChar = 0;
        while (!isdigit(inputLine[onChar])){
            onChar ++;
        }
        sum += 10 * (inputLine[onChar]-'0');

        onChar = inputLine.length()-1;
        while (!isdigit(inputLine[onChar])){
            onChar --;
        }
        sum += inputLine[onChar]-'0';

        inputLine = "";
        cin >> inputLine;
    }

    cout << sum << "\n";

    return 0;
}
