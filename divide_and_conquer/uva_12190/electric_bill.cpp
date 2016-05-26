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
int diff = 0;
int num = 0;
int func(int a){
    if (a <= 100)
        return 2*a;
    else if (a <= 10000)
        return 200 + 3*(a - 100);
    else if (a < 1000000)
        return 29900 + 5*(a - 10000);
    else
        return 4979900 + 7*(a - 1000000);
}

int bisect(int lo, int hi){
    if (lo >= hi)
        return func(hi);
    int mid = (lo + hi)/2;
    int m = func(mid);
    int n = func(num - mid);
    if (n - m > diff)
        return bisect(mid + 1, hi);
    else
        return bisect(lo, mid);
}

int main(){
    int total;
    int a, b;
    while (scanf("%d %d", &total, &diff)){
        if (total == 0 && diff == 0)
            break;
        if (total <= 200)
            num = total/2;
        else if (total <= 29900)
            num = (total - 200)/3 + 100;
        else if (total <= 4979900)
            num = (total - 29900)/5 + 10000;
        else
            num = (total - 4979900)/7 + 1000000;

        int me = bisect(0, num/2);
        printf("%d\n", me);
    }
    return 0;

}
