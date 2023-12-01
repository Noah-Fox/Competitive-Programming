//https://open.kattis.com/problems/splitdecisions

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define prestring first
#define poststring second.first
#define word second.second 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //input n
    ll n;
    cin >> n;

    //input each string
    vector<vector<pair<string,pair<string,string>>>> words(21);
    string gotWord;
    for (ll i = 0; i < n; i ++){
        cin >> gotWord;
        words[gotWord.length()].push_back({gotWord.substr(2,gotWord.length()-2),{"p",gotWord}});
    }


    //perform algorithm on each length of words
    ll sum = 0;
    for (ll l = 3; l <= 20; l ++){
        // cout << "\nsize " << l << "\n";
        //go through every pair of letters in the words
        for (ll i = 0; i < l-1; i ++){
            // cout << "pair " << i << "\n";
            //set pre and poststrings
            for (auto it = words[l].begin(); it != words[l].end(); it ++){
                string onWord = it -> word;
                it -> prestring = onWord.substr(0,i);
                it -> poststring = onWord.substr(i+2);
            }

            //order by pre and poststrings
            sort(words[l].begin(),words[l].end());
        
            //iterate through each word
            unordered_set<string> validOverlaps;
            unordered_set<string> rejectedOverlaps;
            for (auto it = words[l].begin(); it != words[l].end(); it ++){
                for (auto searchIt = it+1; searchIt != words[l].end(); searchIt ++){
                    //check if *it and *searchIt are valid overlaps
                    if (it -> prestring == searchIt -> prestring && it -> poststring == searchIt -> poststring){
                        //get pairs
                        string pair1 = (it -> word).substr(i,2);
                        string pair2 = (searchIt -> word).substr(i,2);
                        string pairCombo = pair1 + pair2;
                        if (pair2 < pair1){
                            pairCombo = pair2 + pair1;
                        }
                        // cout << (it -> word) << " matches " << (searchIt -> word) << " with " << pairCombo << "\n";

                        //check if pairCombo is currently valid
                        if (validOverlaps.count(pairCombo)){
                            validOverlaps.erase(pairCombo);
                            // cout << "\tremove " << pairCombo << " from validOverlaps\n";
                        }
                        //check that pairCombo hasn't been found already
                        else if (rejectedOverlaps.count(pairCombo) == 0){
                            validOverlaps.insert(pairCombo);
                            rejectedOverlaps.insert(pairCombo);
                            // cout << "\tadd " << pairCombo << " to validOverlaps\n";
                        }
                        // else {
                        //     cout << "\t" << pairCombo << " is already rejected\n";
                        // }
                    }
                }
            }

            sum += validOverlaps.size();
        }
    }

    cout << sum << "\n";




    // for (ll i = 3; i < 21; i ++){
    //     cout << "length " << i << "\n";
    //     sort(words[i].begin(), words[i].end());
    //     for (auto it = words[i].begin(); it != words[i].end(); it ++){
    //         cout << (it -> prestring) << " " << (it -> poststring) << " " << (it -> word) << "\n";
    //     }
    //     cout << "\n";
    // }

    return 0;
}

/*
3.ans!                  RSR3.ans                RSR6.ans                RSRrandom100.ans!       RSRrandom30.ans         RSRwordlist642.ans
3.in                    RSR3.in                 RSR6.in                 RSRrandom100.in         RSRrandom30.in          RSRwordlist642.in
RSR.ans                 RSR4.ans                RSR7.ans                RSRrandom20.ans         RSRrandom40.ans         many-pairs.ans
RSR.in                  RSR4.in                 RSR7.in                 RSRrandom20.in          RSRrandom40.in          many-pairs.in
RSR2.ans                RSR5.ans                RSR8.ans                RSRrandom250.ans!       RSRthreeletter.ans!
RSR2.in                 RSR5.in                 RSR8.in                 RSRrandom250.in         RSRthreeletter.in
*/
