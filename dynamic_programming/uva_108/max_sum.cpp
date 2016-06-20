#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <ctype.h>
#include <cmath>
#include <typeinfo>
#include <limits.h>
#include <map>
#include <time.h>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
int main(){
	int dim = 0;
	scanf("%d", &dim);
	int num[100][100] = {0};
	int sum[100][100] = {0};
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			scanf("%d", &num[i][j]);

	for(int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			int up = 0; 
			int left = 0;
			int top = 0;
			if (i > 0 && j > 0)
				top = sum[i-1][j-1];
			if (i > 0)
				up = sum[i-1][j];
			if (j > 0)
				left = sum[i][j-1];
			sum[i][j] = num[i][j] + left + up - top;
		}
	}
	int max_sum = INT_MIN;
	//for each starting point	
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			for (int i2 = i; i2 < dim; i2++){
				for (int j2 = j; j2 < dim; j2++){
					int up = 0; 
					int left = 0;
					int top = 0;
					if (i > 0 && j > 0)
						top = sum[i-1][j-1];
					if (i > 0)
						up = sum[i-1][j2];
					if (j > 0)
						left = sum[i2][j-1];
					int total = sum[i2][j2] - up - left + top;
					if (total > max_sum)
						max_sum = total;
						
				}
			}
		}
	}
	printf("%d\n", max_sum);
	return 0;
}
