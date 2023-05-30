// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int amount;
    cin >> amount;
    vector<ll> divs(amount,0);

    ll sum = 0;
    int tmp;
    for (int i = 0; i < amount; i ++){
        cin >> tmp;
        sum += tmp;
        divs[((sum % amount) + amount) % amount] ++;
        // cout << sum << ": " << (((sum % amount) + amount) % amount) << "\n";
    }

    ll count = 0;
    for (int i = 0; i < amount; i ++){
        // cout << divs[i] << " ";
        if (divs[i] > 1){
            count += divs[i] * (divs[i] - 1) * 0.5;
        }
    }
    // cout << "\n";

    count += divs[0];

    cout << count << "\n";

    return 0;
}
