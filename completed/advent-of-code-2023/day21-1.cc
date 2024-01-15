//Advent of code day 21 puzzle 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    string inLine;
    vector<string> graph;
    ll graphWidth;
    ll graphHeight;
    while (getline(cin,inLine)){
        if (graph.size() == 0){
            graphWidth = inLine.length() + 2;
            string s = "";
            graph.push_back(s.append(graphWidth,'#'));
        }
        graph.push_back('#' + inLine + '#');
    }
    string s = "";
    graph.push_back(s.append(graphWidth,'#'));
    graphHeight = graph.size();

    vector<string> onGraph;
    for (ll y = 0; y < graphHeight; y ++){
        onGraph.push_back(graph[y]);
        for (ll x = 0; x < graphWidth; x ++){
            if (graph[y][x] == 'S'){
                graph[y][x] = '.';
            }
        }
    }

    for (ll i = 0; i < 64; i ++){
        vector<string> nextGraph = graph;
        for (ll y = 0; y < graphHeight; y ++){
            for (ll x = 0; x < graphWidth; x ++){
                if (onGraph[y][x] == 'S'){
                    if (onGraph[y-1][x] == '.'){
                        nextGraph[y-1][x] = 'S';
                    }
                    if (onGraph[y+1][x] == '.'){
                        nextGraph[y+1][x] = 'S';
                    }
                    if (onGraph[y][x-1] == '.'){
                        nextGraph[y][x-1] = 'S';
                    }
                    if (onGraph[y][x+1] == '.'){
                        nextGraph[y][x+1] = 'S';
                    }
                }
            }
        }
        onGraph = nextGraph;
    }

    ll sum = 0;
    for (ll y = 0; y < graphHeight; y ++){
        for (ll x = 0; x < graphWidth; x ++){
            if (onGraph[y][x] == 'S'){
                sum ++;
            }
        }
    }

    cout << sum << "\n";

    return 0;
}
