//https://open.kattis.com/problems/absolutelysymmetric

#include <iostream>
#include <vector>

using namespace std;

void displayMatrix(vector<vector<int> > m){
    for (size_t i = 0; i < m.size(); i ++){
        for (size_t x = 0; x < m[i].size(); x ++){
            cout << m[i][x] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int vSize;
    cin >> vSize;

    vector<vector<int> > sumMatrix;

    for (int i = 0; i < vSize; i ++){
        vector<int> row;
        for (int x = 0; x < vSize; x ++){
            int in;
            cin >> in;
            row.push_back(in);
        }
        sumMatrix.push_back(row);
    }

    vector<vector<int> > ans1(vSize, vector<int>(vSize));
    vector<vector<int> > ans2(vSize, vector<int>(vSize));

    bool hasDiff = false;
    for (int i = 0; i < vSize; i ++){
        ans1[i][i] = sumMatrix[i][i];
        for (int x = 0; x < i; x ++){
            if (abs(sumMatrix[i][x]-sumMatrix[x][i]) % 2 == 0){
                cout << "-1\n";
                return 0;
            }
            if (sumMatrix[i][x] != sumMatrix[x][i]){
                hasDiff = true;
            }
            int mid = sumMatrix[i][x] + (sumMatrix[x][i]-sumMatrix[i][x])/2;
            ans1[i][x] = mid;
            ans1[x][i] = mid;
            ans2[i][x] = sumMatrix[i][x]-mid;
            ans2[x][i] = sumMatrix[x][i]-mid;
        }
    }

    if (hasDiff){
        cout << "2\n";
        displayMatrix(ans1);
        displayMatrix(ans2);
    }
    else{
        cout << "1\n";
        displayMatrix(ans1);
    }


    return 0;
}
