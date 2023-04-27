//https://cses.fi/problemset/task/1091

#include <iostream>
#include <vector>
#include <set>
// #include <bits/stdc++.h>

using namespace std;

int main(){
    int ticketAmount, customerAmount;
    cin >> ticketAmount >> customerAmount;

    multiset<int> tickets;

    for (int i = 0; i < ticketAmount; i ++){
        int addTicket;
        cin >> addTicket;
        tickets.insert(addTicket);
    }
        
    for (int i = 0; i < customerAmount; i ++){
        int customer;
        cin >> customer;
        auto closest = tickets.upper_bound(customer);
        if (closest == tickets.begin()){
            cout << "-1\n";
        }
        else {
            closest --;
            cout << *closest << "\n";
            tickets.erase(closest);
        }
    }


    

    return 0;
}
