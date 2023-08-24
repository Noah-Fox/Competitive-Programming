//https://cses.fi/problemset/task/2193

/**
Given a polygon, find the number of integer coordinate points inside the polygon, and the number on its border

First find the amount of coordinate points on the boundary
- For a line segment from (x1,y1) to (x2,y2), there gcd(|x1-x2|,|y1-y2|)-1 points on it, not including its ends
- Use this to determine the amount of points for each side of the polygon

Next, find the area of the polygon, using the shoelace formula

Then use Pick's theorem to find the number of integer points inside the polygon
    A = a + b/2 - 1
    a = A - b/2 + 1
*/

// #include <iostream>
// #include <vector>
// #include <complex>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0);

    ll vertexAmount;
    cin >> vertexAmount;

    //input vertices
    vector<P> vertices(vertexAmount+1);
    ll x, y;
    for (ll i = 0; i < vertexAmount; i ++){
        cin >> x >> y;
        vertices[i] = {x,y};
    }
    vertices[vertexAmount] = vertices[0];

    //iterate through each side of the polygon, finding boundary points and area
    ll boundarySum = 0;
    ll areaSum = 0;
    auto v1 = vertices.begin();
    auto v2 = vertices.begin()+1;
    while (v2 != vertices.end()){
        //the amount of coordinate points on v1-v2 is the gcd of dx and dy
        ll addBoundary = gcd(abs((v1 -> X) - (v2 -> X)),abs((v1 -> Y) - (v2 -> Y)));
        boundarySum += addBoundary;

        //area is sum of cross product of each pair of vertices
        ll addArea = (conj(*v1) * (*v2)).Y;
        areaSum += addArea;

        v1 ++;
        v2 ++;
    }

    //use rearranged Pick's theorem to find the number of coordinate points inside the polygon
    ll innerSum = (abs(areaSum) - boundarySum) / 2 + 1;

    //output
    cout << innerSum << " " << boundarySum << "\n";

    return 0;
}
