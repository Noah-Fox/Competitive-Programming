//https://cses.fi/problemset/task/1143

// #include <iostream>
// #include <vector>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int findHotel(vector<ll>& hotels, const ll& hotelAmount, const ll& group){
    if (hotels[1] < group){
        return 0;
    }
    int onHotel = 1;
    while (onHotel < hotelAmount){
        if (hotels[2*onHotel] >= group){
            onHotel *= 2;
        }
        else if (hotels[2*onHotel+1] >= group) {
            onHotel = onHotel * 2 + 1;
        }
        else {
            return 0;
        }
    }

    ll toReturn = onHotel-hotelAmount+1;
    hotels[onHotel] -= group;
    while (onHotel > 1){
        onHotel /= 2;
        hotels[onHotel] = max(hotels[onHotel*2],hotels[onHotel*2+1]);
    }
    return toReturn;
}

int main(){
    ios::sync_with_stdio(0);

    ll realHotelAmount, hotelAmount, groupAmount;
    cin >> realHotelAmount >> groupAmount;

    hotelAmount = realHotelAmount;
    if (__builtin_popcount(hotelAmount) > 1){
        ll logVal = log2(hotelAmount)+1;
        hotelAmount = pow(2,logVal);
    }

    vector<ll> hotels(2*hotelAmount,0);

    //input hotels
    for (int i = hotelAmount; i < hotelAmount+realHotelAmount; i ++){
        cin >> hotels[i];
    }

    //create query tree
    for (int i = hotelAmount-1; i > 0; i --){
        hotels[i] = max(hotels[2*i],hotels[2*i+1]);
    }

    //go through groups
    for (int i = 0; i < groupAmount; i ++){
        ll group;
        cin >> group;
        cout << findHotel(hotels,hotelAmount,group) << "\n";
    }


    return 0;
}
