//https://open.kattis.com/problems/display

#include <iostream>

using namespace std;

int main(){
    //top to bottom, left to right
    const bool numCons[7][10] = {
        {1,0,1,1,0,1,1,1,1,1},
        {1,0,0,0,1,1,1,0,1,1},
        {1,1,1,1,1,0,0,1,1,1},
        {0,0,1,1,1,1,1,0,1,1},
        {1,0,1,0,0,0,1,0,1,0},
        {1,1,0,1,1,1,1,1,1,1},
        {1,0,1,1,0,1,1,0,1,1}
    };//  0,1,2,3,4,5,6,7,8,9 

    string time;
    cin >> time;

    while (time != "end"){
        int digits[4];
        digits[0] = time[0]-'0';
        digits[1] = time[1]-'0';
        digits[2] = time[3]-'0';
        digits[3] = time[4]-'0';

        //line 1
        for (int i = 0; i < 4; i ++){
            if (numCons[0][digits[i]] || numCons[1][digits[i]]){
                cout << "+";
            }
            else {
                cout << " ";
            }
            if (numCons[0][digits[i]]){
                cout << "---";
            }
            else {
                cout << "   ";
            }
            if (numCons[0][digits[i]] || numCons[2][digits[i]]){
                cout << "+";
            }
            if (i == 0 || i == 2){
                cout << "  ";
            }
            else if (i == 1){
                cout << "     ";
            }
            else {
                cout << "\n";
            }
        }
        //lines 2 and 3
        for (int x = 0; x < 2; x ++){
            for (int i = 0; i < 4; i ++){
                if (numCons[1][digits[i]]){
                    cout << "|   ";
                }
                else {
                    cout << "    ";
                }
                if (numCons[2][digits[i]]){
                    cout << "|";
                }
                else {
                    cout << " ";
                }
                if (i == 0 || i == 2){
                    cout << "  ";
                }
                else if (i == 3){
                    cout << "\n";
                }
                else if (x == 0){
                    cout << "     ";
                }
                else {
                    cout << "  o  ";
                }
            }
        }
        //line 3
        for (int i = 0; i < 4; i ++){
            if (numCons[3][digits[i]] || numCons[4][digits[i]] || numCons[1][digits[i]]){
                cout << "+";
            }
            else {
                cout << " ";
            }
            if (numCons[3][digits[i]]){
                cout << "---";
            }
            else {
                cout << "   ";
            }
            if (numCons[3][digits[i]] || numCons[5][digits[i]] || numCons[2][digits[i]]){
                cout << "+";
            }
            if (i == 0 || i == 2){
                cout << "  ";
            }
            else if (i == 1){
                cout << "     ";
            }
            else {
                cout << "\n";
            }
        }
        //lines 5 and 6
        for (int x = 0; x < 2; x ++){
            for (int i = 0; i < 4; i ++){
                if (numCons[4][digits[i]]){
                    cout << "|   ";
                }
                else {
                    cout << "    ";
                }
                if (numCons[5][digits[i]]){
                    cout << "|";
                }
                else {
                    cout << " ";
                }
                if (i == 0 || i == 2){
                    cout << "  ";
                }
                else if (i == 3){
                    cout << "\n";
                }
                else if (x == 1){
                    cout << "     ";
                }
                else {
                    cout << "  o  ";
                }
            }
        }
        //line 7
        for (int i = 0; i < 4; i ++){
            if (numCons[6][digits[i]] || numCons[4][digits[i]]){
                cout << "+";
            }
            else {
                cout << " ";
            }
            if (numCons[6][digits[i]]){
                cout << "---";
            }
            else {
                cout << "   ";
            }
            if (numCons[6][digits[i]] || numCons[5][digits[i]]){
                cout << "+";
            }
            if (i == 0 || i == 2){
                cout << "  ";
            }
            else if (i == 1){
                cout << "     ";
            }
            else {
                cout << "\n";
            }
        }
        cout << "\n\n";

        cin >> time;
    }
    cout << "end\n";

    return 0;
}

