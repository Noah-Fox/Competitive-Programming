//Advent of code Day 8 Puzzle 1

#include <iostream>
#include <vector>
#include <string>
#include <map>

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

    ll nodeVal = 0;
    while (getline(cin,inLine)){
        if (inLine.length() > 1){
            onNode = inLine.substr(0,3);
            leftNode = inLine.substr(7,3);
            rightNode = inLine.substr(12,3);

            nodes.push_back(onNode);
            leftNodes.push_back(leftNode);
            rightNodes.push_back(rightNode);

            nodeToNum[onNode] = nodeVal;

            nodeVal ++;
        }
    }

    ll stepCount = 0;
    string atNode = "AAA";
    while (atNode != "ZZZ"){
        if (directions[stepCount % directions.length()] == 'L'){
            atNode = leftNodes[nodeToNum[atNode]];
        }
        else {
            atNode = rightNodes[nodeToNum[atNode]];
        }
        stepCount ++;
    }

    cout << stepCount << "\n";

    return 0;
}
