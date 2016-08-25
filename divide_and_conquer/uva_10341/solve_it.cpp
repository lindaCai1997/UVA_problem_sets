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
int p, q, r, s, t, u;
double error;
double f(double mid){
        return p*exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid)
                + t*mid*mid + u;
}

double bisect(double lo, double hi){
        double mid = (lo + hi)/2;
        double result = f(mid);

        if (result == 0)
                return mid;
        if (hi - lo <= error){
                return lo;
        }
        if (f(lo)*f(mid) <= 0)
                return bisect(lo, mid);
        else
                return bisect(mid, hi);
}

int main(){
        error = 1*pow(10, -7);
        while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6){
                if (f(0)*f(1) > 0){
                        printf("No solution\n");
                }
                else{
                        double num = bisect(0.0,1.0);
                        printf("%.4f\n", num);
                }
        }

        return 0;
}
