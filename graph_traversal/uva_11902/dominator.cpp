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
#include <stack>
#include <queue>

using namespace std;
int matrix[100][100];
int result[100][100] = {0};
int n = 0;
void check_domees(int dom){
    int k = 0;
    std::stack<int> s;
    int trav[100] = {false};
    s.push(0);
    while (!s.empty()){
        k = s.top();
        s.pop();
        result[dom][k] = 1;
        trav[k] = true;
        for (int i = 0; i < n; i++){
            if (k != i && matrix[k][i] == 1 && trav[i] == false){
                s.push(i);
            }
        }
    }
    for (int i = 0; i < 100; i++)
        trav[i] = false;

    s.push(0);
    if (dom != 0){
        while (!s.empty()){
            k = s.top();
            s.pop();
            result[dom][k] = 0;
            trav[k] = true;
            for (int i = 0; i < n; i++){
                if (k != i && matrix[k][i] == 1 && i != dom && trav[i] == false){
                    s.push(i);
                }
            }
        }
    }

}

void print_sline(){
    printf("+");
    for (int j = 0; j < n - 1; j++){
        printf("--");
    }
    printf("-+\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        printf("Case %d:\n", i + 1);
        for (int j = 0; j < 100; j++){
            for (int k = 0; k < 100; k++){
                matrix[j][k] = 0;
                result[j][k] = 0;
            }
        }

        scanf("%d", &n);
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                scanf("%d ", &matrix[j][k]);
            }
        }
        for (int j = 0; j < n; j++){
            check_domees(j);
            print_sline();
            for (int k = 0; k < n; k++){
                printf("|");
                if (result[j][k] == 1)
                    printf("Y");
                else
                    printf("N");

            }
            printf("|\n");
        }
        print_sline();
    }
    return 0;
}
