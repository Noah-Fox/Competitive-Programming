//https://cses.fi/problemset/task/1629

/**
 * given a list of start and end times of movies, find the maximum amount of movies you can go to
 *
 * you can remove any movies with the same start time, keeping the one with the earliest end time
 *
 * store the start times in a sorted array, and the end times and score for each time in maps identified
 * by the start time
 *
 * the score for if you start at the start time of a given movie is the maximum of:
 *      - the score of the next movie
 *      - 1 plus the score of the next movie after the movie ends
 *
 * iterate backwards through the movie, assigning each score
*/

// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll movieAmount;
    cin >> movieAmount;

    //input movies
    vector<ll> startTimes;
    map<ll,ll> endTimes;
    map<ll,ll> scores;
    ll a, b;
    for (ll i = 0; i < movieAmount; i ++){
        cin >> a >> b;
        if (endTimes.count(a)){
            if (endTimes[a] > b){
                endTimes[a] = b;
            }
        }
        else {
            startTimes.push_back(a);
            endTimes[a] = b;
            scores[a] = 0;
        }
    }
    sort(startTimes.begin(),startTimes.end());

    //solve
    ll firstScore = 0;
    for (auto it = startTimes.rbegin(); it != startTimes.rend(); it ++){
        ll start = *it;

        //find score if you don't go to movie
        ll skipScore = 0;
        auto skipIt = lower_bound(startTimes.begin(),startTimes.end(),start+1);
        if (skipIt != startTimes.end()){
            skipScore = scores[*skipIt];
        }

        //find score if you do go to movie
        ll goScore = 1;
        auto goIt = lower_bound(startTimes.begin(),startTimes.end(),endTimes[start]);
        if (goIt != startTimes.end()){
            goScore += scores[*goIt];
        }

        scores[start] = max(skipScore,goScore);
        firstScore = scores[start];
    }

    cout << firstScore << "\n";

    return 0;
}
