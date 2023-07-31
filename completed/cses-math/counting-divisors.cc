//https://cses.fi/problemset/task/1713

/**
 * For each number in a given list, give the amount of divisors the number has
 *
 * Use the sieve of eratosthenese to find every prime and square of a prime less than the largest number.
 * Store the primes in a vector, so it can be iterated through. Also store the primes and the squared primes each
 * in a set, so they can be accessed quickly.
 *
 * The process for finding the amount of divisors of a number n:
 *  - start with a score: 1 if the number is 1. 2 if it is a prime. 3 if it is a square of a prime. 4 if else
 *  - iterate p through the prime numbers until p is greater than the square root of n
 *      - for each p, if it divides n, divide n by p until it is no longer divisible. Multiply the score by
 * the amount of divisions made
*/

// #include <iostream>
// #include <vector>
// #include <map>
// #include <set>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void sieve(vector<ll>& primes, set<ll>& primeSet, set<ll>& squarePrimeSet, ll n){
    vector<ll> allNums(n+1,true);
    for (ll i = 2; i <= n; i ++){
        if (allNums[i]){
            primes.push_back(i);
            primeSet.insert(i);
            squarePrimeSet.insert(i*i);
            for (ll x = i*i; x <= n; x += i){
                allNums[x] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    ll numAmount;
    cin >> numAmount;

    //input numbers
    vector<ll> nums(numAmount);
    ll maxNum = 0;
    for (ll i = 0; i < numAmount; i ++){
        cin >> nums[i];
        if (nums[i] > maxNum){
            maxNum = nums[i];
        }
    }

    //find all primes and square-primes
    vector<ll> primes;
    set<ll> primeSet;
    set<ll> squarePrimeSet;
    sieve(primes,primeSet,squarePrimeSet,maxNum);
    
    //solve
    vector<bool> numActive(numAmount,true);
    vector<ll> numCount(numAmount,1);
    bool active = true;
    ll onPrime = 0;
    while (active){
        active = false;

        for (ll i = 0; i < numAmount; i ++){
            if (numActive[i]){
                if (primes[onPrime]*primes[onPrime]*primes[onPrime] > nums[i]){
                    numActive[i] = false;

                    if (primeSet.count(nums[i])){
                        numCount[i] *= 2;
                    }
                    else if (squarePrimeSet.count(nums[i])){
                        numCount[i] *= 3;
                    }
                    else if (nums[i] != 1){
                        numCount[i] *= 4;
                    }
                }
                else {
                    active = true;
                    ll count = 1;
                    while (nums[i] % primes[onPrime] == 0){
                        nums[i] /= primes[onPrime];
                        count ++;
                    }
                    numCount[i] *= count;
                }
            }
        }

        onPrime ++;
    }

    //output solutions
    for (ll i = 0; i < numAmount; i ++){
        cout << numCount[i] << "\n";
    }

    return 0;
}
