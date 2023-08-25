//https://cses.fi/problemset/task/2194

// #include <iostream>
// #include <vector>
// #include <complex>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
#define X first
#define Y second

const ll MAX = 4000000000000000007;

ll sqDist(P a, P b){
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

ll intRoot(ll a){
    ll r = sqrt(a);
    return r;
}

ll solve(vector<P>& points, ll begin, ll end){

    //base case: no points
    if (end == begin){
        return MAX;
    }
    //base case: 1 point
    if (end - begin <= 1){
        return MAX;
    }
    //base case: two points
    if (end - begin == 2){
        if (points[begin].Y > points[begin+1].Y){
            swap(points[begin],points[begin+1]);
        }
        return sqDist(points[begin],points[begin+1]);
    }

    //recurse
    ll split = begin + (end-begin)/2;
    ll midX = points[split].X;
    ll leftMin = solve(points, begin, split);
    ll rightMin = solve(points, split, end);
    
    ll minDist = min(leftMin,rightMin);
    ll centerDist = intRoot(minDist);

    //merge leftYSort and rightYSort into ySort, and find all points close to the center
    vector<P> centerPoints;


    //copy the left and right portions into new vectors
    vector<P> leftYSort(split-begin);
    vector<P> rightYSort(end-split);
    for (ll i = begin; i < split; i ++){
        leftYSort[i-begin] = points[i];
    }
    for (ll i = split; i < end; i ++){
        rightYSort[i-split] = points[i];
    }
    auto leftIt = leftYSort.begin();
    auto rightIt = rightYSort.begin();

    ll pointsIndex = begin;
    while (leftIt != leftYSort.end() && rightIt != rightYSort.end()){
        if ((leftIt -> Y) < (rightIt -> Y)){
            points[pointsIndex] = *leftIt;
            pointsIndex ++;

            if (abs((leftIt -> X) - midX) <= centerDist){
                centerPoints.push_back(*leftIt);
            }

            leftIt ++;
        }
        else {
            points[pointsIndex] = *rightIt;
            pointsIndex ++;

            if (abs((rightIt -> X) - midX) <= centerDist){
                centerPoints.push_back(*rightIt);
            }

            rightIt ++;
        }
    }
    while (leftIt != leftYSort.end()){
        points[pointsIndex] = *leftIt;
        pointsIndex ++;

        if (abs((leftIt -> X) - midX) <= centerDist){
            centerPoints.push_back(*leftIt);
        }

        leftIt ++;
    }
    while (rightIt != rightYSort.end()){
        points[pointsIndex] = *rightIt;
        pointsIndex ++;

        if (abs((rightIt -> X) - midX) <= centerDist){
            centerPoints.push_back(*rightIt);
        }

        rightIt ++;
    }


    //check all possible pairs in the center column
    for (auto it = centerPoints.begin(); it != centerPoints.end(); it ++){
        for (auto next = it+1; next != centerPoints.end(); next ++){
            if ((next -> Y) - (it -> Y) > centerDist){
                break;
            }
            if (sqDist(*it,*next) < minDist){
                minDist = sqDist(*it,*next);
                centerDist = intRoot(minDist);
            }
        }
    }

    return minDist;

}

int main(){
    ios::sync_with_stdio(0);

    ll pointAmount;
    cin >> pointAmount;

    //input points
    ll x, y;
    vector<P> points(pointAmount);
    for (ll i = 0; i < pointAmount; i ++){
        cin >> x >> y;
        points[i] = {x,y};
    }

    //sort the points
    sort(points.begin(),points.end());

    ll minDist = solve(points,0,pointAmount);

    cout << minDist << "\n";

    return 0;
}
