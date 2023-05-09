//https://cses.fi/problemset/task/1158

#include <iostream>
#include <vector>
#include <utility>
//#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int>> vp;

int recurse(const vp& books, int onBook, int pageCount, int priceCount, int maxPrice){
    if (onBook >= books.size()){
        return pageCount;
    }
    if (priceCount > maxPrice){
        return pageCount;
    }

    int noAdd = recurse(books,onBook+1,pageCount,priceCount,maxPrice);
    int withAdd = recurse(books,onBook+1,pageCount+books[onBook].second,priceCount+books[onBook].first,maxPrice);

    if (noAdd > withAdd){
        return noAdd;
    }
    return withAdd;
}

int main(){
    ios::sync_with_stdio(0);

    int bookAmount, maxPrice;
    cin >> bookAmount >> maxPrice;

    vp books(bookAmount);


    for (int i = 0; i < bookAmount; i ++){
        cin >> books[i].first;
    }
    for (int i = 0; i < bookAmount; i ++){
        cin >> books[i].second;
    }

    int result = recurse(books,0,0,0,maxPrice);

    cout << result << "\n";

    return 0;
}
