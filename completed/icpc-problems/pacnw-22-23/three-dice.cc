//icpc pacific northwest regional contest 2022-23

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string recurse(set<char> die0, set<char> die1, set<char> die2, const vector<string>& words, int wordOn, string addWord){
    die0.insert(addWord[0]);
    die1.insert(addWord[1]);
    die2.insert(addWord[2]);
    if (wordOn >= words.size()){
        for (char a = 'a'; a <= 'z'+1; a ++){
            if (die0.size() == 6 && die1.size() == 6 && die2.size() == 6){
                string ans = "";
                for (auto i = die0.begin(); i != die0.end(); i ++){
                    ans += *i;
                }
                ans += ' ';
                for (auto i = die1.begin(); i != die1.end(); i ++){
                    ans += *i;
                }
                ans += ' ';
                for (auto i = die2.begin(); i != die2.end(); i ++){
                    ans += *i;
                }
                return ans;
            }
            if (!die0.count(a) && !die1.count(a) && !die2.count(a)){
                if (die0.size() < 6){
                    die0.insert(a);
                }
                else if (die1.size() < 6){
                    die1.insert(a);
                }
                else if (die2.size() < 6){
                    die2.insert(a);
                }
            }
        }
        return "0";
    }
    string word = words[wordOn];


    for (int i = 0; i < 6; i ++){
        if (!die0.count(word[1]) && !die0.count(word[2]) && !die1.count(word[0]) && !die1.count(word[2]) && !die2.count(word[0]) && !die2.count(word[1])){
            string result = recurse(die0,die1,die2,words,wordOn+1,word);
            if (result.length() > 1){
                return result;
            }
        }
        next_permutation(word.begin(),word.end());
    }
    return "0";
}

int main(){
    ios::sync_with_stdio(0);

    int wordAmount;
    cin >> wordAmount;

    vector<string> words(wordAmount);
    for (int i = 0; i < wordAmount; i ++){
        cin >> words[i];
        if (words[i][0] == words[i][1] || words[i][0] == words[i][2] || words[i][1] == words[i][2]){
            cout << "0\n";
            return 0;
        }
    }


    set<char> die0;
    set<char> die1;
    set<char> die2;

    // die0.insert(words[0][0]);
    // die1.insert(words[0][1]);
    // die2.insert(words[0][2]);

    

    cout << recurse(die0,die1,die2,words,1,words[0]) << "\n";

    return 0;
}
