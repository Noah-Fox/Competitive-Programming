//icpc pacnw 22-23 regionals

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int lastSun, sunLength, lastMoon, moonLength;
    cin >> lastSun >> sunLength >> lastMoon >> moonLength;

    int onSun = sunLength-lastSun;
    int onMoon = moonLength-lastMoon;

    while (onSun <= 5000 && onMoon <= 5000){
        if (onSun == onMoon){
            cout << onSun << "\n";
            return 0;
        }
        if (onSun < onMoon){
            onSun += sunLength;
        }
        else {
            onMoon += moonLength;
        }
    }

    return 0;
}
