//https://cses.fi/problemset/task/2195

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <complex>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
#define X first
#define Y second 

//returns (c - a) x (c - b)
ll cross(P a, P b, P c){
    return (c.X - a.X) * (c.Y - b.Y) - (c.Y - a.Y) * (c.X - b.X);
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
    sort(points.begin(),points.end());

    //find top hull
    stack<ll> topHull;//stores index of each point on the top side of the hull
    stack<ll> prevTopHull;//stores index of each point on the top side of the hull, except for the last
    topHull.push(0);
    topHull.push(1);
    prevTopHull.push(0);
    ll hullCount = 2;

    for (ll i = 2; i < pointAmount; i ++){
        //pop topHull until line from previous point to current point to i turns right
        while (!prevTopHull.empty() && cross(points[prevTopHull.top()], points[topHull.top()], points[i]) > 0){
            prevTopHull.pop();
            topHull.pop();
            hullCount --;
        }
        prevTopHull.push(topHull.top());
        topHull.push(i);
        hullCount ++;
    }

    //find bottom hull
    for (ll i = pointAmount - 2; i >= 0; i --){
        while (!prevTopHull.empty() && cross(points[prevTopHull.top()], points[topHull.top()], points[i]) > 0){
            prevTopHull.pop();
            topHull.pop();
            hullCount --;
        }
        prevTopHull.push(topHull.top());
        topHull.push(i);
        hullCount ++;
    }

    cout << hullCount-1 << "\n";
    topHull.pop();
    while (!topHull.empty()){
        cout << points[topHull.top()].X << " " << points[topHull.top()].Y << "\n";
        topHull.pop();
    }

    return 0;
}
