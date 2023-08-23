//https://cses.fi/problemset/task/2190

/**
 * For each test case, given two line segments, determine if the lines are intersecting
 *
 * There are 3 cases for overlapping line segments:
 *  1. They share a common vertex
 *      - check each pair of vertices for equality
 *  2. They are on the same line and overlap
 *      - check if they are on the same line using cross products
 *      - check if they are overlapping using the distances from every point to every point
 *  3. They have a single intersection point
 *      - Use cross products to determine which side of the other line a vertex is on
 *      - If both pairs of vertices are on opposite sides of the other line, the lines are crossing
*/

#include <iostream>
#include <complex>

using namespace std;

typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

ll crossDir(P a, P b){
    ll c = (conj(a) * b).Y;
    if (c < 0) return -1;
    if (c > 0) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);

    ll testAmount;
    cin >> testAmount;

    for (ll i = 0; i < testAmount; i ++){
        ll x, y;
        P p1, p2, p3, p4;
        cin >> x >> y;
        p1 = {x,y};
        cin >> x >> y;
        p2 = {x,y};
        cin >> x >> y;
        p3 = {x,y};
        cin >> x >> y;
        p4 = {x,y};

        //check if the lines have a common vertex
        if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4){
            cout << "YES\n";
            continue;
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
                cout << "YES\n";
                continue;
            }
        }

        //check if the line segments have one intersection
        if (c1 != c2 && c3 != c4){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }

    return 0;
}
