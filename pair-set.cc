#include <unordered_set>
#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;

// Hash function  
struct hashFunction 
{ 
  size_t operator()(const pair<ll ,  
                    ll> &x) const
  { 
    return x.first ^ x.second; 
  } 
}; 

int main(){
    unordered_set<pair<ll, ll>, hashFunction> myUnorderedSet;

    myUnorderedSet.insert(make_pair(5,5));
    myUnorderedSet.insert(make_pair(1,3));
    myUnorderedSet.insert(make_pair(-5,5));
    myUnorderedSet.insert(make_pair(5,-5));
    myUnorderedSet.insert(make_pair(-5,-5));
    myUnorderedSet.insert(make_pair(15,-5));
    
    auto gotPair = myUnorderedSet.find(make_pair(1,3));
    cout << (gotPair -> first) << " " << (gotPair -> second) << "\n";

    return 0;
}
