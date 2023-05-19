//https://open.kattis.com/problems/pebblesolitaire

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool canMoveFromRight(const vector<bool>& b, int pos){
    return (pos < 10) && !b[pos] && b[pos+1] && b[pos+2];
}

bool canMoveFromLeft(const vector<bool>& b, int pos){
    return (pos > 1) && !b[pos] && b[pos-1] && b[pos-2];
}

vector<bool> moveFromRight(vector<bool> b, int pos){
    b[pos] = true;
    b[pos+1] = false;
    b[pos+2] = false;
    return b;
}

vector<bool> moveFromLeft(vector<bool> b, int pos){
    b[pos] = true;
    b[pos-1] = false;
    b[pos-2] = false;
    return b;
}

int main(){
    int caseAmount;
    cin >> caseAmount;

    for (int caseOn = 0; caseOn < caseAmount; caseOn ++){
        int pieceAmount = 0;
        vector<bool> board(12);
        for (int i = 0; i < 12; i ++){
            char p;
            cin >> p;
            board[i] = (p == 'o');
            if (board[i]){
                pieceAmount ++;
            }
        }
        stack< vector<bool> > moves;
        moves.push(board);
        int moveAmounts = 0;
        while (!moves.empty()){
            stack< vector<bool> > nextMoves;
            while (!moves.empty()){
                vector<bool> onBoard = moves.top();
                moves.pop();
                for (int i = 0; i < 12; i ++){
                    if (canMoveFromLeft(onBoard,i)){
                        nextMoves.push(moveFromLeft(onBoard,i));
                    }
                    if (canMoveFromRight(onBoard,i)){
                        nextMoves.push(moveFromRight(onBoard,i));
                    }
                }
            }
            moves = nextMoves;
            moveAmounts ++;
        }
        moveAmounts --;
        cout << (pieceAmount-moveAmounts) << "\n";
    }
    
    return 0;
}

/*
5
---oo-------
-o--o-oo----
-o----ooo---
oooooooooooo
oooooooooo-o

*/
