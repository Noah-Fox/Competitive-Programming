//Advent of code Day 8 Puzzle 2

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(){
    string directions;
    cin >> directions;

    string inLine, onNode, leftNode, rightNode;

    map<string,ll> nodeToNum;
    vector<string> leftNodes;
    vector<string> rightNodes;
    vector<string> nodes;
    vector<string> atNodes;

    //input graph
    ll nodeVal = 0;
    while (getline(cin,inLine)){
        if (inLine.length() > 1){
            onNode = inLine.substr(0,3);
            leftNode = inLine.substr(7,3);
            rightNode = inLine.substr(12,3);

            nodes.push_back(onNode);
            leftNodes.push_back(leftNode);
            rightNodes.push_back(rightNode);

            if (onNode[2] == 'A'){
                atNodes.push_back(onNode);
            }

            nodeToNum[onNode] = nodeVal;

            nodeVal ++;
        }
    }

    //find for each path a loop that it follows and all z-nodes it reaches
    //After running this on the input data, it is revealed that every path reaches only a single
    //z-node, and reaches it repeatedly at regular intervals, meaning the solution can be found 
    //with the LCM
    cout << directions.length() << "\n";
    vector<ll> zLoops;
    for (size_t i = 0; i < atNodes.size(); i ++){
        ll stepCount = 0;
        set<string> startNodes;
        vector<ll> startedOnStep(nodes.size(),-1);
        vector<ll> foundZs;
        while (!(stepCount % directions.length() == 0 && startNodes.count(atNodes[i]) > 0)){
            if (stepCount % directions.length() == 0){
                startNodes.insert(atNodes[i]);
                startedOnStep[nodeToNum[atNodes[i]]] = stepCount;
            }

            if (atNodes[i][2] == 'Z'){
                foundZs.push_back(stepCount);
            }


            if (directions[stepCount % directions.length()] == 'L'){
                atNodes[i] = leftNodes[nodeToNum[atNodes[i]]];
            }
            else {
                atNodes[i] = rightNodes[nodeToNum[atNodes[i]]];
            }

            stepCount ++;
        }

        cout << startedOnStep[nodeToNum[atNodes[i]]] << " - " << stepCount << " " << stepCount-startedOnStep[nodeToNum[atNodes[i]]] << " " << atNodes[i] << "\n";
        for (size_t x = 0; x < foundZs.size(); x ++){
            cout << " " << foundZs[x] << "\n";
        }
        zLoops.push_back(foundZs[0]);
    }

    //get prime factorization of each loop size and the LCM
    vector<vector<ll>> primeFacts(zLoops.size(),vector<ll>(2,0));
    vector<ll> lcm;
    for (size_t i = 0; i < zLoops.size(); i ++){
        for (ll x = 2; x <= zLoops[i]; x ++){
            primeFacts[i].push_back(0);
            while (zLoops[i] % x == 0){
                cout << zLoops[i] << "/" << x << " = ";
                zLoops[i] /= x;
                cout << zLoops[i] << "\n";
                primeFacts[i][x] ++;
            }

            while (primeFacts[i].size() > lcm.size()){
                lcm.push_back(0);
            }
            while (primeFacts[i][x] > lcm[x]){
                lcm[x] ++;
            }
        }
    }

    cout << "\n\n";
    for (size_t i = 0; i < primeFacts.size(); i ++){
        for (size_t x = 0; x < primeFacts[i].size(); x ++){
            if (primeFacts[i][x] > 0){
                cout << x << "^" << primeFacts[i][x] << " * ";
            }
        }
        cout << "\n\n";
    }
    for (size_t x = 0; x < lcm.size(); x ++){
        if (lcm[x] > 0){
            cout << x << "^" << lcm[x] << " * ";
        }
    }
    cout << "\n\n";

    //find the lcm
    ll lcmProduct = 1;
    for (size_t i = 2; i < lcm.size(); i ++){
        lcmProduct *= pow(i,lcm[i]);
    }
    cout << lcmProduct << "\n";

    return 0;
}
