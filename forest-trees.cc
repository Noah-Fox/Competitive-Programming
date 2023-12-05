//https://open.kattis.com/problems/forestforthetrees2

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Hash function  
struct hashFunction 
{ 
  size_t operator()(const pair<ll ,  
                    ll> &x) const
  { 
    return x.first ^ x.second; 
  } 
}; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll treeAmount, sensedAmount, senseRadius;
    cin >> treeAmount >> sensedAmount >> senseRadius;

    //input all trees
    vector<pair<ll,ll>> trees(treeAmount);
    for (ll i = 0; i < treeAmount; i ++){
        cin >> trees[i].first >> trees[i].second;
    }


    //input sensed trees
    vector<pair<ll,ll>> sensedTrees(sensedAmount);
    for (ll i = 0; i < sensedAmount; i ++){
        cin >> sensedTrees[i].first >> sensedTrees[i].second;
    }

    //value to store found possible position
    pair<ll,ll> foundPos;
    bool hasFoundPos = false;

    //for each four rotations of the sensed trees
    for (ll onRotation = 0; onRotation < 4; onRotation ++){
        //rotate sensed trees 90 degrees
        for (ll i = 0; i < sensedAmount; i ++){
            sensedTrees[i] = {sensedTrees[i].second,-sensedTrees[i].first};
        }

        //fill a set with every sensed tree relative to first tree
        unordered_set<pair<ll,ll>, hashFunction> sTreeSet;
        for (ll i = 0; i < sensedAmount; i ++){
            sTreeSet.insert({sensedTrees[i].first-sensedTrees[0].first,sensedTrees[i].second-sensedTrees[0].second});
        }

        //iterate through every tree
        for (ll i = 0; i < treeAmount; i ++){
            bool validTree = true;
            unordered_set<pair<ll,ll>, hashFunction> onTreeSet = sTreeSet;

            //position that robot would be in if current tree is the right one
            pair<ll,ll> testRobotPos = make_pair(trees[i].first-sensedTrees[0].first, trees[i].second-sensedTrees[i].second);

            //iterate through every other tree
            for (ll x = 0; x < treeAmount && validTree; x ++){
                //find position of xTree to iTree
                ll distX = trees[x].first - trees[i].first;
                ll distY = trees[x].second - trees[i].second;
                pair<ll,ll> dist = make_pair(distX,distY);

                //check if tree is out of range
                if (abs(trees[x].first-testRobotPos.first) + abs(trees[x].second-testRobotPos.second) <= senseRadius){
                    //check if tree is in the set of sensed trees
                    auto found = onTreeSet.find(dist);
                    if (found != onTreeSet.end()){
                        //remove tree from set of sensed trees
                        onTreeSet.erase(found);
                    }
                    else {
                        //not in set, therefore invalid
                        validTree = false;
                    }
                }
            }

            //check if the tree works
            if (validTree && onTreeSet.empty()){
                if (hasFoundPos){
                    cout << "Ambiguous\n";
                    return 0;
                }
                hasFoundPos = true;
                // foundPos = {trees[i].first-sensedTrees[0].first,trees[i].second-sensedTrees[0].second};
                foundPos = testRobotPos;
            }
        }
    }

    //output solution
    if (hasFoundPos){
        cout << foundPos.first << " " << foundPos.second << "\n";
    }
    else {
        cout << "Impossible\n";
    }

    return 0;
}
