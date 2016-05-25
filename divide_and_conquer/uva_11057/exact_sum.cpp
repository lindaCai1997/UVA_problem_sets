#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <fstream>
#include <map>
#include <ctype.h>
#include <cmath>
#include <typeinfo>
#include <limits.h>
#include <map>
#include <time.h>
#include <string.h>

using namespace std;
int first, second;
vector<int> books;
int money;

int bisect(int lo, int hi_l, int hi_h){
    if (hi_l >= hi_h)
        return hi_h;
    else if (hi_l == hi_h - 1)
        return (books[lo] + books[hi_l] >= money) ? hi_l : hi_h;
    else{
        int mid = (hi_l + hi_h) /2;
        if (books[lo] + books[mid] < money)
            return bisect(lo, mid + 1, hi_h);
        else
            return bisect(lo, hi_l, mid);
    }

}

void find_fit(int lo, int hi){
    if (lo >= hi)
        return;

    int fit = bisect(lo, lo, hi);
    if (books[lo] + books[fit] == money){
        first = books[lo];
        second = books[fit];
    }

    find_fit(lo + 1, fit);

}

int main(){
    int num = 0;
    while (scanf("%d", &num) == 1){
        int price;
        for (int i = 0; i < num; i++){
            scanf("%d", &price);
            books.push_back(price);
        }
        scanf("%d", &money);
        std::sort(books.begin(), books.end());
        find_fit(0, num - 1);
        printf("Peter should buy books whose prices are %d and %d.\n\n", first, second);
        books.clear();
    }
    return 0;

}
