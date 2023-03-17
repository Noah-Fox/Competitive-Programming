//https://open.kattis.com/problems/cetvrta

#include <iostream>
#include <set>

using namespace std;

int main(){
    multiset<int> xVals;
    multiset<int> yVals;
    
    for (int i = 0; i < 3; i ++){
        int x, y;
        cin >> x >> y;
        xVals.insert(x);
        yVals.insert(y);
    }
    
    for (auto i = xVals.begin(); i != xVals.end(); i ++){
        if (xVals.count(*i) == 1){
            cout << *i << " ";
        }
    }
    for (auto i = yVals.begin(); i != yVals.end(); i ++){
        if (yVals.count(*i) == 1){
            cout << *i << "\n";
        }
    }
    
    return 0;
}
