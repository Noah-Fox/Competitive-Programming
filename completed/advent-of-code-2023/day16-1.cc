//Advent of code day 16 puzzle 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

struct Tile{
    char elem;
    vector<bool> energized;

    Tile(char e){elem = e; energized = vector<bool>(4,false);}
};

struct Beam{
    ll dir = 1;//up = 0; right = 1; down = 2; left = 3;
    ll x = 0;
    ll y = 0;

    bool move(ll graphWidth, ll graphHeight){
        if (dir == 0) y --;
        else if (dir == 1) x ++;
        else if (dir == 2) y ++;
        else x --;


        if (y < 0 || y >= graphHeight || x < 0 || x >= graphWidth){
            return false;
        }
        return true;
    }
};

int main(){
    string inLine;
    vector<vector<Tile>> graph;

    vector<ll> neSlash = {1,0,3,2};
    vector<ll> nwSlash = {3,2,1,0};
    vector<vector<ll>> nSplit = {{0},{0,2},{2},{0,2}};
    vector<vector<ll>> eSplit = {{1,3},{1},{1,3},{3}};

    while (getline(cin,inLine)){
        vector<Tile> graphLine;
        for (size_t i = 0; i < inLine.length(); i ++){
            graphLine.push_back(Tile(inLine[i]));
        }
        graph.push_back(graphLine);
    }

    ll graphHeight = graph.size();
    ll graphWidth = graph[0].size();

    queue<Beam> beamQ;
    beamQ.push(Beam());
    while (!beamQ.empty()){
        Beam onBeam = beamQ.front();
        beamQ.pop();

        if (!graph[onBeam.y][onBeam.x].energized[onBeam.dir]){
            graph[onBeam.y][onBeam.x].energized[onBeam.dir] = true;
            char onElem = graph[onBeam.y][onBeam.x].elem;
            if (onElem == '/'){
                onBeam.dir = neSlash[onBeam.dir];
                Beam nextBeam = onBeam;

                if (nextBeam.move(graphWidth,graphHeight)){
                    beamQ.push(nextBeam);
                }
            }
            else if (onElem == '\\'){
                onBeam.dir = nwSlash[onBeam.dir];
                Beam nextBeam = onBeam;
                if (nextBeam.move(graphWidth,graphHeight)){
                    beamQ.push(nextBeam);
                }
            }
            else if (onElem == '|'){
                for (size_t j = 0; j < nSplit[onBeam.dir].size(); j ++){
                    Beam nextBeam = onBeam;
                    nextBeam.dir = nSplit[onBeam.dir][j];
                    if (nextBeam.move(graphWidth,graphHeight)){
                        beamQ.push(nextBeam);
                    }
                }
            }
            else if (onElem == '-'){
                for (size_t j = 0; j < eSplit[onBeam.dir].size(); j ++){
                    Beam nextBeam = onBeam;
                    nextBeam.dir = eSplit[onBeam.dir][j];
                    if (nextBeam.move(graphWidth,graphHeight)){
                        beamQ.push(nextBeam);
                    }
                }
            }
            else {
                Beam nextBeam = onBeam;
                if (nextBeam.move(graphWidth,graphHeight)){
                    beamQ.push(nextBeam);
                }
            }
        }
    }



    ll sum = 0;
    for (size_t i = 0; i < graph.size(); i ++){
        for (size_t x = 0; x < graph[i].size(); x ++){
            if (graph[i][x].energized[0] || graph[i][x].energized[1] || graph[i][x].energized[2] || graph[i][x].energized[3]){
                sum ++;
            }
        }
    }

    cout << sum << "\n";

    return 0;
}

/*

######....
.#...#....
.#...#####
.#...##...
.#...##...
.#...##...
.#..####..
########..
.#######..
.#...#.#..

######....
.#...#....
.#...#####
.#...##...
.#...##...
.#...##...
.#..####..
.#######..
.#######..
.#...#.#..

*/
