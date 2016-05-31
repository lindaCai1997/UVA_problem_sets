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

int main(){
    double p = 0;
    while (scanf("%lf", &p) > 0 ){
        while ( p > 0){
            if (p <= 9){
                printf("Stan wins.\n");
                break;
            }
            else if (p > 9 && p <= 18){
                printf("Ollie wins.\n");
                break;
            } 
            else
                p /= 18;
        }    
    } 
    return 0;
}
