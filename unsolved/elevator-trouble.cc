//https://open.kattis.com/problems/elevatortrouble

#include <iostream>
#include <stack>

using namespace std;

int solve(int floorAmount, int startFloor, int goalFloor, int upAmount, int downAmount){
if (upAmount == 0 && (goalFloor > startFloor || (startFloor-goalFloor) % downAmount != 0)){
        return -1;
    }
    if (downAmount == 0 && (goalFloor < startFloor || (goalFloor-startFloor) % downAmount != 0)){
        return -1;
    }
    if (startFloor == goalFloor){
        return 0;
    }
    if (upAmount == downAmount && abs(startFloor-goalFloor) % upAmount != 0){
        return -1;
    }

    int floors[floorAmount+1];
    for (int i = 0; i <= floorAmount; i ++){
        floors[i] = -1;
    }
    floors[startFloor] = 0;

    int onMove = 0;

    stack<int> moves;
    moves.push(startFloor);
    while (!moves.empty()){
        onMove ++;
        stack<int> nextMoves;
        while (!moves.empty()){
            int onFloor = moves.top();
            moves.pop();
            if (onFloor > downAmount && floors[onFloor-downAmount] == -1){
                floors[onFloor-downAmount] = onMove;
                nextMoves.push(onFloor-downAmount);
            }
            if (onFloor + upAmount <= floorAmount && floors[onFloor+upAmount] == -1){
                floors[onFloor+upAmount] = onMove;
                nextMoves.push(onFloor+upAmount);
            }
        }
        if (floors[goalFloor] != -1){
            return floors[goalFloor];
        }
        moves = nextMoves;
    }
    if (floors[goalFloor] == -1){
        return -1;
    }
    else {
        return floors[goalFloor];
    }
}

int main(){

    int floorAmount, startFloor, goalFloor, upAmount, downAmount;
    cin >> floorAmount >> startFloor >> goalFloor >> upAmount >> downAmount;

    int answer = solve(floorAmount,startFloor,goalFloor,upAmount,downAmount);
    if (answer == -1){
        cout << "use the stairs\n";
    }
    else{
        cout << answer << "\n";
    }


    // srand(time(nullptr));

    // for (int i = 0; i < 100; i ++){
    //     floorAmount = rand()%1000000;
    //     startFloor = rand()%floorAmount + 1;
    //     goalFloor = rand()%floorAmount + 1;
    //     upAmount = rand()%1000000;
    //     downAmount = rand()%1000000;

    //     int answer = solve(floorAmount,startFloor,goalFloor,upAmount,downAmount);
    //     if (answer == -1){
    //         cout << "use the stairs\n";
    //     }
    //     else{
    //         cout << answer << "\n";
    //     }
    // }

    return 0;
}
