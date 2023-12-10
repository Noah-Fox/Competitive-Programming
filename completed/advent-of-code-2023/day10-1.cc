//Advent of code day 10 puzzle 1

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef long long ll;

int main(){
    //input
    string inLine;
    vector<string> maze;
    while (getline(cin,inLine)){
        maze.push_back(inLine);
    }

    ll mazeWidth = maze[0].length();
    ll mazeHeight = maze.size();
    ll startX, startY;

    //find starting point
    for (ll y = 0; y < mazeHeight; y ++){
        for (ll x = 0; x < mazeWidth; x ++){
            if (maze[y][x] == 'S'){
                startX = x;
                startY = y;
            }
        }
    }

    //find direction of loop from starting point
    pair<ll,ll> nextDir;
    if (startX > 0 && (maze[startY][startX-1] == '-' || maze[startY][startX-1] == 'F' || maze[startY][startX-1] == 'L')){
        nextDir = {-1,0};
    }
    else if (startX < mazeWidth-1 && (maze[startY][startX+1] == '-' || maze[startY][startX+1] == 'J' || maze[startY][startX+1] == '7')){
        nextDir = {1,0};
    }
    else {
        nextDir = {0,1};
    }

    //go through loop
    ll onX = startX;
    ll onY = startY;
    ll loopSize = 0;
    while (maze[onY][onX] != 'S' || loopSize == 0){
        loopSize ++;
        char nextPipe = maze[onY+nextDir.second][onX+nextDir.first];
        onY += nextDir.second;
        onX += nextDir.first;
        if (nextPipe == 'F'){
            if (nextDir.first == -1){
                nextDir = {0,1};
            }
            else {
                nextDir = {1,0};
            }
        }
        else if (nextPipe == 'J'){
            if (nextDir.first == 1){
                nextDir = {0,-1};
            }
            else {
                nextDir = {-1,0};
            }
        }
        else if (nextPipe == 'L'){
            if (nextDir.first == -1){
                nextDir = {0,-1};
            }
            else {
                nextDir = {1,0};
            }
        }
        else if (nextPipe == '7'){
            if (nextDir.first == 1){
                nextDir = {0,1};
            }
            else {
                nextDir = {-1,0};
            }
        }
    }

    cout << loopSize/2 << "\n";

    return 0;
}
