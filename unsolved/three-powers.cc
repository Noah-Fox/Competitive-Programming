//https://open.kattis.com/problems/threepowers
#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(){

    typedef long long ll;

    ll inVal;
    cin >> inVal;

    while (inVal){
        inVal --;
        ll count = 1;
        bool onFirst = true;

        ll copy = inVal;
        while (copy > 0){
            cout << (copy%2);
            copy /= 2;
        }

        while (inVal > 0){
            if (inVal % 2 == 1){
                if (onFirst){
                    cout << "{ ";
                    onFirst = false;
                }
                else {
                    cout << ", ";
                }
                cout << count;
            }
            count *= 3;
            inVal /= 2;
        }
        
        // for (ll bitVal = 1; bitVal <= inVal; bitVal = bitVal << 1){
        //     if (bitVal & inVal){
        //         cout << "<" << bitVal << ": " << (bitVal & inVal) << ">";
        //         if (onFirst){
        //             cout << "{ ";
        //             onFirst = false;
        //         }
        //         else {
        //             cout << ", ";
        //         }
        //         cout << count;
        //     }
        //     count *= 3;
        // }
        if (onFirst){
            cout << "{";
        }
        cout << " }\n";

        cin >> inVal;
    }

    return 0;
}
