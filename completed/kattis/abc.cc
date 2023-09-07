

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> vals(3);
    cin >> vals[0] >> vals[1] >> vals[2];
    sort(vals.begin(),vals.end());
    
    string order;
    cin >> order;
    
    for (int i = 0; i < 3; i ++){
        if (order[i] == 'A') cout << vals[0] << " ";
        else if (order[i] == 'B') cout << vals[1] << " ";
        else cout << vals[2] << " ";
    }
    
    return 0;
}
