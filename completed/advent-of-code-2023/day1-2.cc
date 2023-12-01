//Advent of Code 2023 Day 1 Puzzle 2

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll sum = 0;

    string numStrings[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<ll> numProgress(10,0);

    string inputLine = "";
    cin >> inputLine;
    while (inputLine != ""){

        numProgress = vector<ll>(10,0);
        ll foundNum = -1;
        for (ll i = 0; i < inputLine.length() && foundNum == -1; i ++){
            if (isdigit(inputLine[i])){
                foundNum = inputLine[i]-'0';
                break;
            }

            for (ll x = 0; x < 10; x ++){
                if (inputLine[i] == numStrings[x][numProgress[x]]){
                    numProgress[x] ++;
                    if (numProgress[x] == numStrings[x].length()){
                        foundNum = x;
                        break;
                    }
                }
            }
        }
        sum += 10 * (foundNum);

        for (ll x = 0; x < 10; x ++){
            numProgress[x] = numStrings[x].length()-1;
        }
        foundNum = -1;
        for (ll i = inputLine.length()-1; i >= 0 && foundNum == -1; i --){
            if (isdigit(inputLine[i])){
                foundNum = inputLine[i]-'0';
                break;
            }

            for (ll x = 0; x < 10; x ++){
                if (inputLine[i] == numStrings[x][numProgress[x]]){
                    numProgress[x] --;
                    if (numProgress[x] == -1){
                        foundNum = x;
                        break;
                    }
                }
            }
        }
        sum += foundNum;

        inputLine = "";
        cin >> inputLine;
    }

    cout << sum << "\n";

    return 0;
}
