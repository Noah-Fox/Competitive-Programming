//https://cses.fi/problemset/task/1619

// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int amount;
    cin >> amount;

    vector<int> arrivals(amount);
    vector<int> departures(amount);

    for (int i = 0; i < amount; i ++){
        cin >> arrivals[i];
        cin >> departures[i];
    }

    sort(arrivals.begin(),arrivals.end());
    sort(departures.begin(),departures.end());

    auto onArrival = arrivals.begin();
    auto onDeparture = departures.begin();

    int currentAmount = 0;
    int maxAmount = 0;
    while (onArrival != arrivals.end() && onDeparture != departures.end()){
        if (onArrival == arrivals.end()){
            currentAmount --;
            onDeparture ++;
        }
        else if (*onArrival < *onDeparture){
            currentAmount ++;
            onArrival ++;
            if (currentAmount > maxAmount){
                maxAmount = currentAmount;
            }
        }
        else {
            currentAmount --;
            onDeparture ++;
        }
    }
    cout << maxAmount << "\n";

    return 0;
}
