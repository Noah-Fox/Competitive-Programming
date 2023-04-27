//https://cses.fi/problemset/task/1163

// #include <iostream>
// #include <vector>
// #include <set>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int streetLength, lightAmount;
    cin >> streetLength >> lightAmount;
    
    //vector<int> lightPositions;
    set<int> lightPositions;
    //vector<int> spaces;
    multiset<int> spaces;

    lightPositions.insert(0);
    lightPositions.insert(streetLength);
    spaces.insert(streetLength);

    int onPosition;

    for (int i = 0; i < lightAmount; i ++){
        cin >> onPosition;
        lightPositions.insert(onPosition);
        auto posIter = lightPositions.find(onPosition);
        auto nextIter = next(posIter,1);
        auto prevIter = prev(posIter,1);
        //auto insertAt = upper_bound(lightPositions.begin(),lightPositions.end(),onPosition);
        
        //auto removeSpace = lower_bound(spaces.begin(),spaces.end(),*(nextIter)-*(prevIter));
        //spaces.erase(removeSpace);
        int removeSpaceSize = *nextIter-*prevIter;
        spaces.erase(spaces.find(removeSpaceSize));

        int spaceBefore = onPosition - *(prevIter);
        int spaceAfter = *(nextIter) - onPosition;

        // spaces.insert(upper_bound(spaces.begin(),spaces.end(),spaceBefore),spaceBefore);
        // spaces.insert(upper_bound(spaces.begin(),spaces.end(),spaceAfter),spaceAfter);
        spaces.insert(spaceBefore);
        spaces.insert(spaceAfter);

        //lightPositions.insert(insertAt,onPosition);


        cout << *spaces.rbegin() << "\n";
    }

    return 0;
}
