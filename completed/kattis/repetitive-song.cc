//https://open.kattis.com/problems/repetitivesong

/*
 * Given a sequence of strings, find the length of the longest non-unique subsequence 
 *      example: (a b c b d) has two (a b d) subsequences. Its solution is therefore 3
 *
 * This length is equal to the number of words minus the smallest distance between any two equivalent words
*/

// #include <iostream>
// #include <vector>
// #include <map>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll wordAmount;
    cin >> wordAmount;

    unordered_map<string,ll> lastPos;
    string word;
    ll closestPair = 100000007;
    ll anyPair = false;
    string wordPair = "";
    //input each word, check the last time it was given, and record its position
    for (ll i = 0; i < wordAmount; i ++){
        cin >> word;
        if (lastPos.count(word) == 0){//unordered_map.contains() does not work in kattis
            lastPos[word] = i;
        }
        else{
            if (i - lastPos[word] < closestPair){
                closestPair = i - lastPos[word];
                anyPair = true;
                wordPair = word;
            }
            lastPos[word] = i;
        }
        
    }


    if (anyPair){
        cout << wordAmount - closestPair << "\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}
