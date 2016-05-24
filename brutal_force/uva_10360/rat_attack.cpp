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
#include <vector>

using namespace std;

int main(){
    int x1, x2, y1, y2;
    int x, y;
    int scene, d, n, p;
    scanf("%d", &scene);
    while(scene > 0){
        int rats[1024][1024] = {0};
        int result[1024][1024] = {0};
        scanf("%d", &d);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &p);
            rats[x][y] = p;
            x1 = x - d > 0 ? x - d : 0;
            x2 = x + d > 1023 ? 1023 : x + d;
            for (int j = x1; j <= x2; j++){
                y1 = y - d;
                if (y1 < 0)
                    y1 = 0;
                y2 = y + d;
                if (y2 > 1023)
                    y2 = 1023;
                for (int k = y1; k <= y2; k++){
                    result[j][k] += p;
                }
            }
        }
        x = 0; y = 0;
        for (int i = 0; i < 1024; i++){
            for (int j = 0; j < 1024; j++){
                if (result[i][j] > result[x][y]){
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d %d\n", x, y, result[x][y]);
        scene--;
    }
    return 0;
}
