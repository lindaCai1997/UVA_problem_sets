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
char bigint[1000];
int num_3(){
    int a = 0;
    for (int i = 0; i < strlen(bigint); i++){
        if (bigint[i] == '3' || bigint[i] == '6' || bigint[i] == '9'){
            a++;
        }
    }
    return a;
}

int first_move(){
    int sum = 0;
    for (int i = 0; i < strlen(bigint); i++){
        char c = bigint[i];
        sum += atoi(&c);
    }
    if (strlen(bigint) == 1)
        return 3;
    else if (sum % 3 == 0)
        return 2;
    else{
        sum = sum % 3;
        for (int i = 0; i < strlen(bigint); i++){
            char c = bigint[i];
            int a = atoi(&c);
            if (a % 3 == sum)
                return 1;
        }
        return 0;
    }
}

int main(){
    int num = 0;
    bool first_win = false;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++){
        char n = 0;
        int pos = 0;
        for (int j = 0; j < 1000; j++){
            bigint[j] = 0;
        }

        while (scanf("%c", &n) > 0){
            if (n != '\n')
                bigint[pos++] = n;
            else
                break;
        }

        int success = first_move();
        int threes = num_3();
        if (success == 3)
            first_win = true;
        else if (success == 2){
            if (threes % 2 == 1)
                first_win = true;
            else
                first_win = false;
        }
        else if (success == 0)
            first_win = false;
        else{
            if (threes % 2 == 0)
                first_win = true;
            else
                first_win = false;
        }
        printf("Case %d: %c\n", i + 1, first_win? 'S' : 'T');
    }
    return 0;

}
