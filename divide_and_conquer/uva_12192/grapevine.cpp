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
int matrix[500][500] = {0};
int dim_x, dim_y;

int find_x(int x_lo, int x_hi, int y, int mi){
    if (x_lo >= x_hi){
        if (matrix[x_hi][y] >= mi)
            return x_hi;
        else
            return -1;
    }
    int x_mid = (x_lo + x_hi)/2;
    if (matrix[x_mid][y] >= mi)
        return find_x(x_lo, x_mid, y, mi);
    else
        return find_x(x_mid + 1, x_hi, y, mi);
}

int find_square(int x, int y, int ma){
    int size = min(dim_x - x, dim_y - y);
    for (int i = 0 ; i < size; i++){
        if (matrix[x + i][y + i] > ma)
            return i;
    }
    return size;
}

int main(){
    int num;
    while (scanf("%d %d", &dim_x, &dim_y) == 2){
        if (dim_x == 0 && dim_y == 0)
            break;
        for (int i = 0; i < dim_x; i++){
            for (int j = 0; j < dim_y; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        scanf("%d", &num);
        for (int i = 0; i < num; i++){
            int mi, ma, max_result, result;
            max_result = 0;
            result = 0;
            scanf("%d %d", &mi, &ma);
            for (int j = 0; j < dim_y; j++){
                int x = find_x(0, dim_x - 1, j, mi);
                if (x != -1)
                    result = find_square(x, j, ma);
                if (result > max_result)
                    max_result = result;
            }
            printf("%d\n", max_result);
        }
        printf("-\n");
        for (int i = 0; i < 500; i++)
            for (int j = 0; j < 500; j++)
                matrix[i][j] = 0;
    }
    return 0;
}
