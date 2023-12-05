//Advent of code Day 5 Puzzle 2

//Note: only works because I got lucky. Does not consider when a transformation range is fully within a source range

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    
    // vector<ll> srcVals;
    vector<pair<ll,ll> > srcRanges;
    string str1, str2;

    //input seed line
    cin >> str1 >> str1;
    while (str1 != "seed-to-soil"){
        cin >> str2;
        ll num1 = stoll(str1);
        ll num2 = stoll(str2);
        
        srcRanges.push_back({num1,num2});

        cin >> str1;
    }

    

    for (ll i = 0; i < 7; i ++){
        vector<pair<ll,ll> > destRanges = srcRanges;

        cin >> str1 >> str1;
        ll srcStart, destStart, rangeLength;

        while (isdigit(str1[0])){
            destStart = stoll(str1);
            cin >> srcStart >> rangeLength;


            for (size_t x = 0; x < srcRanges.size(); x ++){
                //check if srcRange starts in tRange
                if (srcRanges[x].first >= 0 && srcRanges[x].first >= srcStart && srcRanges[x].first-srcStart < rangeLength){
                    //check if srcRange is completely inside tRange
                    if (srcRanges[x].first + srcRanges[x].second - 1 - srcStart <= rangeLength){
                        destRanges[x].first = destStart + (srcRanges[x].first-srcStart);
                        srcRanges[x] = {-1,0};
                    }
                    //only beginning of srcRange is in tRange
                    else{
                        ll inRangeLength = srcStart + rangeLength - srcRanges[x].first;
                        srcRanges.push_back({srcRanges[x].first+inRangeLength,srcRanges[x].second-inRangeLength});
                        destRanges.push_back({srcRanges[x].first+inRangeLength,srcRanges[x].second-inRangeLength});


                        destRanges[x].first = destStart + (srcRanges[x].first-srcStart);
                        destRanges[x].second = inRangeLength;

                        srcRanges[x] = {-1,0};

                        if (srcRanges[srcRanges.size()-1].second < 0){
                            cout << "negative A\n";
                        }
                        if (destRanges[x].second < 0){
                            cout << "negative B\n";
                        }
                    }
                }
                //check if end of srcRange is in tRange
                else if (srcRanges[x].first >= 0){
                    ll srcRangeEnd = srcRanges[x].first + srcRanges[x].second - 1;
                    if (srcRangeEnd >= srcStart && srcRangeEnd-srcStart < rangeLength){
                        ll inRangeLength = srcRangeEnd - srcStart + 1;

                        destRanges.push_back({destStart,inRangeLength});
                        srcRanges.push_back({-1,0});

                        srcRanges[x].second -= inRangeLength;
                        destRanges[x].second -= inRangeLength;
                    }
                }
            }

            cin >> str1;
        }

        srcRanges = destRanges;
    }
    

    ll minVal = srcRanges[0].first;
    for (size_t i = 1; i < srcRanges.size(); i ++){
        minVal = min(minVal,srcRanges[i].first);
    }
    cout << minVal << "\n";


    return 0;
}
