//Advent of code day 10 puzzle 2

//This solution is not fully functional. It gets one line wrong, and I just had to output the map it makes and find the incorrect
// parts to manually change the answer it gave

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
    vector<vector<bool> > isPipe(mazeHeight,vector<bool>(mazeWidth,false));

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
    pair<ll,ll> startDir = nextDir;

    //go through loop
    ll onX = startX;
    ll onY = startY;
    ll loopSize = 0;
    while (maze[onY][onX] != 'S' || loopSize == 0){
        loopSize ++;
        isPipe[onY][onX] = true;
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

    //Replace the start pipe with an actual pipe
    char startDirWord;
    char endDirWord;
    if (startDir.first == 0){
        if (startDir.second == 1){
            startDirWord = 'r';
        }
        else {
            startDirWord = 'l';
        }
    }
    else if (startDir.first == 1){
        startDirWord = 'd';
    }
    else {
        startDirWord = 'u';
    }
    if (nextDir.first == 0){
        if (nextDir.second == 1){
            endDirWord = 'r';
        }
        else {
            endDirWord = 'l';
        }
    }
    else if (nextDir.first == 1){
        endDirWord = 'd';
    }
    else {
        endDirWord = 'u';
    }

    vector<vector<char> > directionPipes = {
        {'u', 'u', '|'},
        {'u', 'r', 'F'},
        {'u', 'l', '7'},
        {'r', 'u', 'J'},
        {'r', 'r', '-'},
        {'r', 'd', '7'},
        {'d', 'r', 'L'},
        {'d', 'd', '|'},
        {'d', 'l', 'J'},
        {'l', 'u', 'L'},
        {'l', 'd', 'F'},
        {'l', 'l', '-'}
    };

    for (size_t i = 0; i < directionPipes.size(); i ++){
        if (startDirWord == directionPipes[i][1] && endDirWord == directionPipes[i][0]){
            maze[startY][startX] = directionPipes[i][2];
        }
    }

    //iterate through every row
    ll sum = 0;
    for (ll y = 0; y < mazeHeight; y ++){
        bool inLoop = false;
        char startedPipeAt;
        for (ll x = 0; x < mazeWidth; x ++){
            if (isPipe[y][x]){
                cout << maze[y][x];

                if (maze[y][x] == '|'){
                    inLoop = !inLoop;
                }
                else if (maze[y][x] == 'L' || maze[y][x] == 'F'){
                    startedPipeAt = maze[y][x];
                }
                else if (maze[y][x] == '7' && startedPipeAt == 'L'){
                    inLoop = !inLoop;
                }
                else if (maze[y][x] == 'J' && startedPipeAt == 'F'){
                    inLoop = !inLoop;
                }
            }
            else if (inLoop){
                sum ++;
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << "\n";
    }



    /*
    
    F-7
    F-J
    L-7
    L-J

    */

    cout << sum << "\n";

    return 0;
}

