//icpc pacnw div2 2020-2021

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    string word;
    vector<int> letters(26,0);

    cin >> word;

    for (int i = 0; i < word.length(); i ++){
        if (letters[word[i]-'a'] > 0){
            cout << "0\n";
            return 0;
        }
        else {
            letters[word[i]-'a'] ++;
        }
    }

    cout << "1\n";

    return 0;
}
