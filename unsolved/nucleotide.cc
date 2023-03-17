//https://open.kattis.com/problems/nucleotides

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(){
    string dna;
    cin >> dna;

    int amounts[4][dna.length()+1];
    char molecules[] = {'C','G','T','A'};

    for (size_t i = 0; i <= dna.length(); i ++){
        for (int x = 0; x < 4; x ++){
            int prev = 0;
            if (i > 0){
                prev = amounts[x][i-1];
            }
            if (i < dna.length() && dna[i] == molecules[x]){
                prev ++;
            }
            amounts[x][i] = prev;
        }
    }

    int sectionAmount;
    cin >> sectionAmount;

    for (int i = 0; i < sectionAmount; i ++){
        int startPoint, endPoint;
        cin >> startPoint >> endPoint;
        startPoint --;
        endPoint --;
        vector< pair<int,char> > counts;
        for (int x = 0; x < 4; x ++){
            pair<int,char> countAt;
            countAt.second = molecules[x];
            countAt.first = amounts[x][endPoint+1]-amounts[x][startPoint];
            counts.push_back(countAt);
        }
        sort(counts.rbegin(),counts.rend());
        for (int x = 0; x < 4; x ++){
            cout << counts[x].second << "(" << counts[x].first << ") ";
        }
        cout << "\n";
    }

    return 0;
}
