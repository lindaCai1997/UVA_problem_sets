#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctype.h>
#include <cmath>
#include <typeinfo>
#include <limits.h>
#include <map>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;
int a[1010],  m, n;
bool simulation(int capacity){
        int curr = 0;
        int sofar = 1;
        for (int i = 0; i < n; i++){
                if (a[i] > capacity)
                        return false;
                curr += a[i];
                if (curr > capacity){
                        curr = a[i];
                        sofar++;
                }
                if (sofar > m)
                        return false;
        }
        return true;
}

int main(){
        while(scanf("%d %d", &n, &m) == 2){
                for (int i = 0; i < n; i++){
                        scanf("%d", &a[i]);
                }
                int hi, lo;
                hi = 1*pow(10, 9);
                lo = 1;
                while (lo < hi){
                        int mid = (lo + hi)/2;
                        bool result = simulation(mid);
                        if (result == false)
                                lo = mid + 1;
                        else{
                                if (hi - lo == 1)
                                        break;
                                else
                                        hi = mid;
                        }

                }
                printf("%d\n", lo);
        }
        return 0;
}
