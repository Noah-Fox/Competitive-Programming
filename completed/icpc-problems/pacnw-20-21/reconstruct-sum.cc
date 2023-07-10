//pacnw div2 2020-2021

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);

    ll numAmount;
    cin >> numAmount;

    set <ll> nums;
    ll sum = 0;
    ll a;
    for (ll i = 0; i < numAmount; i ++){
        cin >> a;
        nums.insert(a);
        sum += a;
    }

    if (sum % 2 == 1){
        cout << "BAD\n";
        return 0;
    }

    if (nums.count(sum/2)){
        cout << sum/2 << "\n";
    }
    else {
        cout << "BAD\n";
    }


    return 0;
}
