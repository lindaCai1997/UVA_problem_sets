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

using namespace std;

int main(){
    long int a1,a2,a3,b1,b2,b3,c1,c2,c3;

    string  m1[6];
    m1[0] = "BCG";
    m1[1] = "BGC";
    m1[2] = "CBG";
    m1[3] = "CGB";
    m1[4] = "GBC";
    m1[5] = "GCB";

    while (scanf("%ld", &a1) != EOF){
        scanf("%ld%ld%ld%ld%ld%ld%ld%ld",&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3);
        long int s[6];
         s[0] = a2+a3+b1+b2+c1+c3;
         s[1] = a2+a3+b1+b3+c1+c2;
         s[2] = a1+a2+b2+b3+c1+c3;
         s[3] = a1+a2+b1+b3+c2+c3;
         s[4] = a1+a3+b2+b3+c1+c2;
         s[5] = a1+a3+b1+b2+c2+c3;
        long int sum = INT_MAX; int sumnum = 0;
        
        for (int i = 0; i < 6; i++){
            if (sum > s[i]){
                sum = s[i];
                sumnum = i;
            }
        }

        cout<<m1[sumnum]<<" "<<sum<<endl;
    }
    return 0;
