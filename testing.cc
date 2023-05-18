#include <iostream>
#include <fstream>

using namespace std;


typedef long long ll;

int main(){
    ifstream correctOutput, myOutput, input;
    correctOutput.open("correct_output.txt");
    myOutput.open("my_output.txt");
    input.open("input.txt");

    int numAmount, queryAmount, nums;
    input >> numAmount >> queryAmount;
    for (int i = 0; i < numAmount; i ++){
        input >> nums;
    }

    int my, cor;
    int amountWrong = 0;
    int amount = 0;
    int queryType, a, b, u;
    while (!input.eof()){
        input >> queryType;
        if (queryType == 1){
            input >> a >> b >> u;
        }
        else{
            input >> a;
            correctOutput >> cor;
            myOutput >> my;

            cout << cor << " " << my << " [" << a << "]";
            if (cor == my){
                cout << "\n";
            }
            else {
                cout << " X\n";
            }

            amount ++;

            if (cor != my){
                amountWrong ++;
            }
        }
    }

    cout << amountWrong << "/" << amount << " wrong\n";

    correctOutput.close();
    myOutput.close();
    input.close();

    return 0;
}
