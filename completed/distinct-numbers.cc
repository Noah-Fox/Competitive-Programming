//https://cses.fi/problemset/task/1621

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int inputAmount;
    set <int> inputs;

    cin >> inputAmount;
    for (int i = 0; i < inputAmount; i ++){
        int gotInput;
        cin >> gotInput;
        inputs.insert(gotInput);
    }
    cout << inputs.size() << "\n";

    

    return 0;
}
