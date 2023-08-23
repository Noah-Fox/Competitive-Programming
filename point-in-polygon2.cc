/**

Points:
1. p1: The point that you are determining to be inside or outside the polygon
2. p2: p1 1000000000 to the right or left
3. v1: The previous vertex to the segment you are testing for intersection with
4. v2: The first vertex to the segment you are testing
5. v3: The second vertex to the segment
6. v4: The vertex after the segment
7. beginDir: the side of p1-p2 that v1 is on, to be saved when p1-p2 overlaps v2-v3 and v3-v4
8. endDir: the side of p1-p2 that v4 is on, to be saved when p1-p2 overlaps v1-v2 and v2-v3, but no
    beginDir has been recorded yet
9. intersectSum: the count of intersections made

Functions:
1. dir(a,b,c): The side of the line through a and b that c is on
        - Equal to (c-a)x(b-a)
        - Can be 1, 0, or -1
2. dist(a,b): The distance between points a and b
3. intersect(a,b,c,d): the line segments a-b and c-d intersect
        - dir(a,b,c) != 0 && dir(a,b,d) != 0 && dir(a,b,c) != dir(a,b,d)
        - dir(c,d,a) != 0 && dir(c,d,b) != 0 && dir(c,d,a) != dir(c,d,b)
4. onLine(a,b,c): c is on the line segment a-b
        - dir(a,b,c) == 0 && dist(a,c) <= dist(a,b) && dist(c,b) <= dist(c,a)

Cases:
1. No intersection with v2-v3           +0
2. Intersection with v2-v3              +1
        - intersect(p1,p2,v2,v3)
3. p1 is on line segment v2-v3           X
        - onLine(v2,v3,p1)
4. Touching v2                          +0
5. Crossing v2                          +1
        - onLine(p1,p2,v2)
        - dir(p1,p2,v1) != 0 && dir(p1,p2,v3) != 0 && dir(p1,p2,v1) != dir(p1,p2,v3)
6. Touching v3                          +0
7. Crossing v3                          +0
8. Overlap with v1-v2                   +0
9. Touch overlap with v2-v3             +0
10. Cross overlap with v2-v3            +1
        - onLine(p1,p2,v2) && onLine(p1,p2,v3)
        - dir(p1,p2,v1) != dir(p1,p2,v4)
11. Overlap with v3-v4                  +0
12. Overlap with v2-v3 and v3-v4        
        - onLine(p1,p2,v2) && onLine(p1,p2,v3) && onLine(p1,p2,v4)
        - beginDir = dir(p1,p2,v1)
13. Overlap with v1-v2 and v2-v3
        - onLine(p1,p2,v1) && onLine(p1,p2,v2) && onLine(p1,p2,v3)
        - if (beginDir == 0) endDir = dir(p1,p2,v4)
        - else if (beginDir != endDir) intersectSum ++
14. Overlap with all segments
        - onLine(p1,p2,v1) && onLine(p1,p2,v2) && onLine(p1,p2,v3) && onLine(p1,p2,v4)

End cleanup:
- if (beginDir != endDir) intersectSum ++

*/

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

//given points a, b, and c, returns the side of the line through a and b that c is on
//returns -1, 0, or 1
ll dir(P a, P b, P c){
    ll d = (conj(c-a)*(c-b)).Y;
    if (d < 0) return -1;
    if (d > 0) return 1;
    return 0;
}

//given points a and b, returns the distance from a to b
ll dist(P a, P b){
    return abs(a-b);
}

//given points a, b, c, d, returns true if the line segments a-b and c-d intersect (not on their vertices)
bool intersect(P a, P b, P c, P d){
    return dir(a,b,c) != 0 && dir(a,b,d) != 0 && dir(a,b,c) != dir(a,b,d) && dir(c,d,a) != 0 && dir(c,d,b) != 0 && dir(c,d,a) != dir(c,d,b);
}

//given points a, b, and c, return true if c is on the line segment a-b
bool onLine(P a, P b, P c){
    return dir(a,b,c) == 0 && dist(a,c) <= dist(a,b) && dist(b,c) <= dist(b,a);
}

int main(){
    ios::sync_with_stdio(0);

    ll vertexAmount, pointAmount;
    cin >> vertexAmount >> pointAmount;

    //input vertices
    vector<P> vertices(vertexAmount);
    ll x, y;
    for (ll i = 0; i < vertexAmount; i ++){
        cin >> x >> y;
        vertices[i] = {x,y};
    }

    //input and process points
    for (ll i = 0; i < pointAmount; i ++){
        //input p1 and define p2
        cin >> x >> y;
        P p1 = {x,y};
        P p2;
        if (x < 0){
            p2 = {x-1000000007,y};
        }
        else {
            p2 = {x+1000000007,y};
        }

        //initialize v1, v2, v3, and v4
        auto v1Iter = vertices.begin();
        auto v2Iter = vertices.begin()+1;
        auto v3Iter = vertices.begin()+2;
        auto v4Iter = vertices.begin()+3;
        if (v4Iter == vertices.end()){
            v4Iter = vertices.begin();
        }

        //iterate through every side of the polygon until v1 is at the end
        ll intersectSum = 0;
        ll beginDir = 0;
        ll endDir = 0;
        while (true){
            //create point values using iterators
            P v1 = *v1Iter;
            P v2 = *v2Iter;
            P v3 = *v3Iter;
            P v4 = *v4Iter;

            //check for case 3: on line
            if (onLine(v2,v3,p1)){
                intersectSum = -1;
                break;
            }

            //set onLine and dir values
            bool v1OnLine = onLine(p1,p2,v1);
            bool v2OnLine = onLine(p1,p2,v2);
            bool v3OnLine = onLine(p1,p2,v3);
            bool v4OnLine = onLine(p1,p2,v4);
            ll v1Dir = dir(p1,p2,v1);
            ll v3Dir = dir(p1,p2,v3);
            ll v4Dir = dir(p1,p2,v4);

            //check for v2-v3 overlap cases
            if (v2OnLine && v3OnLine){
                //check for case 12: overlap v2-v3 and v3-v4
                if (v4OnLine && !v1OnLine){
                    beginDir = v1Dir;
                }

                //check for case 13: overlap v1-v2 and v2-v3
                else if (v1OnLine && !v4OnLine){
                    if (beginDir == 0) endDir = v4Dir;
                    else if (beginDir != v4Dir) intersectSum ++;
                }

                //check for case 10: cross overlap v2-v3
                else if (!v1OnLine && !v4OnLine && v1Dir != v4Dir){
                    intersectSum ++;
                }
            }

            //check for case 5: cross v2
            else if (v2OnLine){
                if (v1Dir != 0 && v3Dir != 0 && v1Dir != v3Dir){
                    intersectSum ++;
                }
            }

            //check for case 2: intersect with v2-v3
            else if (intersect(p1,p2,v2,v3)){
                intersectSum ++;
            }


            //increment v1,v2,v3,v4
            v1Iter ++;
            if (v1Iter == vertices.end()) break;
            v2Iter ++;
            if (v2Iter == vertices.end()) v2Iter = vertices.begin();
            v3Iter ++;
            if (v3Iter == vertices.end()) v3Iter = vertices.begin();
            v4Iter ++;
            if (v4Iter == vertices.end()) v4Iter = vertices.begin();
        }
        //clean up
        if (beginDir != endDir){
            intersectSum ++;
        }

        //process intersectSum value and output
        if (intersectSum == -1){
            cout << "BOUNDARY\n";
        }
        else if (intersectSum % 2 == 0){
            cout << "OUTSIDE\n";
        }
        else {
            cout << "INSIDE\n";
        }
    }

    return 0;
}
