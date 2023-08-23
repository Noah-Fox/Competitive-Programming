//https://cses.fi/problemset/task/2192

// #include <iostream>
// #include <vector>
// #include <complex>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

//cross product
ll crossDir(P a, P b){
    ll c = (conj(a)*b).Y;
    if (c < 0) return -1;
    if (c > 0) return 1;
    return 0;
}

//p1 and p2 are the point and a line far to the right or left of it
//p3 and p4 are the vertices of the line segment
//nextP is the next vertex, which is used if p4 is on the line
bool linesIntersecting(P p1, P p2, P p3, P p4, P nextP){
    //check if the lines have a common vertex
    if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4){
        return true;
    }

    ll c1 = crossDir(p1-p3,p1-p4);
    ll c2 = crossDir(p2-p3,p2-p4);
    ll c3 = crossDir(p3-p1,p3-p2);
    ll c4 = crossDir(p4-p1,p4-p2);

    //check if the line segments are on the same line and overlap
    if (c1 == 0 && c2 == 0){
        //find the distances from each point to every other point
        ll d12 = abs(p1-p2);
        ll d13 = abs(p1-p3);
        ll d14 = abs(p1-p4);

        ll d23 = abs(p2-p3);
        ll d24 = abs(p2-p4);

        ll d34 = abs(p3-p4);
        
        if ((d13 <= d12 && d23 <= d12) || (d14 <= d12 && d24 <= d12) || (d14 <= d34 && d13 <= d14) || (d24 <= d34 && d23 <= d34)){
            return true;
        }
    }

    //check if p4 is on the line
    if (c4 == 0)

    //check if the line segments have one intersection
    if (c1 != c2 && c3 != c4){
        return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);

    ll vertexAmount, pointAmount;
    cin >> vertexAmount >> pointAmount;

    //input vertices
    vector<P> vertices(vertexAmount+1);
    ll x, y;
    for (ll i = 0; i < vertexAmount; i ++){
        cin >> x >> y;
        vertices[i] = {x,y};
    }
    vertices[vertexAmount] = vertices[0];

    //input points and solve for each
    for (ll i = 0; i < pointAmount; i ++){
        cin >> x >> y;
        P p1 = {x,y};
        P p2;
        if (x < 0){
            p2 = {x-1000000000,y};
        }
        else {
            p2 = {x+1000000000,y};
        }

        ll crossSum = 0;
        auto preVert = vertices.begin();
        auto nextVert = vertices.begin()+2;
        for (auto it = vertices.begin()+1; it != vertices.end(); it ++){
            ll pCross = crossDir(p1-*it,p1-*preVert);
            if (pCross == 0){
                crossSum = -1;
                break;
            }

            //check if horizontal line crosses side
            if (linesIntersecting(p1,p2,*it,*preVert,*nextVert)){
                crossSum ++;
            }

            preVert++;
            nextVert ++;
            if (nextVert = vertices.end()){
                nextVert = vertices.begin()+1;
            }
        }
        if (crossSum == -1){
            cout << "BOUNDARY\n";
        }
        else if (crossSum % 2 == 0){
            cout << "OUTSIDE\n";
        }
        else {
            cout << "INSIDE\n";
        }
    }

    return 0;
}
