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
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        int f, box;
        scanf("%d %d", &f, &box);
        long long int total  = 0;
        for (int j = 0; j < box; j++){
            long long int sum = 1; 
            int num2 = 0; 
            int temp = 0;
            scanf("%d", &num2);
            for (int k = 0; k < num2; k++){
                    scanf("%d", &temp);
                    sum *= temp;
                    sum = sum % f;
            }
            total += sum;   
        }
        printf("%lld\n", total % f); 
    }
    return 0;   
}  
