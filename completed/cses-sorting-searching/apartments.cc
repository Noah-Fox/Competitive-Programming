//https://cses.fi/problemset/task/1084

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int applicantAmount, apartmentAmount, maxDiff;
    vector<int> applicants;
    vector<int> apartments;

    cin >> applicantAmount >> apartmentAmount >> maxDiff;

    for (int i = 0; i < applicantAmount; i ++){
        int a;
        cin >> a;
        applicants.push_back(a);
    }
    sort(applicants.begin(),applicants.end());
    for (int i = 0; i < apartmentAmount; i ++){
        int a;
        cin >> a;
        apartments.push_back(a);
    }
    sort(apartments.begin(),apartments.end());

    int apartmentOn = 0;
    int applicantOn = 0;
    int amount = 0;

    while (apartmentOn < apartmentAmount && applicantOn < applicantAmount){
        // cout << applicantOn << " " << apartmentOn << " ";
        if (abs(apartments[apartmentOn]-applicants[applicantOn]) <= maxDiff){
            amount ++;
            apartmentOn ++;
            applicantOn ++;
            // cout << "match\n";
        }
        else if (applicants[applicantOn] < apartments[apartmentOn]){
            applicantOn ++;
            // cout << "move applicant\n";
        }
        else {
            apartmentOn ++;
            // cout << "move apartment\n";
        }
    }

    cout << amount << "\n";


    return 0;
}
