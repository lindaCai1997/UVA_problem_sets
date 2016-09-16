#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
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

using namespace std;

int main(){

    long long int num1; long long int num2;
    long long int ij[100000] = {0};
    bool flag = true;
    size_t size = 0;
    while (scanf("%lld", &num1) == 1){
        scanf("%lld", &num2);
        long long int curr = num1;
        if (num1 < 2 || num2 < 2 || num1 < num2){
            printf("Boring!\n");

        }
        else{
            while (curr >= 1){
                if (curr == 1){
                    ij[size++] = curr;
                    break;
                }
                else if (curr % num2 != 0){
                    printf("Boring!\n");
                    flag = false;
                    break;
                }
                else{
                    ij[size++] = curr;
                    curr = curr / num2;
                }
            }

            if (flag == true){
                for (size_t i = 0; i < size - 1; i++){
                    printf("%lld ", ij[i]);
                }
                printf("%lld\n", ij[size-1]);
            }

            flag = true;
            size = 0;
        }
    }
