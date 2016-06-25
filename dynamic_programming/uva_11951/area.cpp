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
long long int matrix[105][105] = {0};
long long int area, sum, n, m, k= 0;
long long int* find_area(int x1, int y1){
	long long int corr_sum = INT_MAX;
	long long int sum = 0;
	long long int area = 0;
	
	for (int i = x1 + 1; i <= n; i++)
		for (int j = y1 + 1; j <= m; j++){
			int area_2 = (i - x1)*(j - y1);
			if (area_2 >= area){
				sum = matrix[i][j] - matrix[x1][j] - matrix[i][y1] + matrix[x1][y1];
				if (sum <= k){
					if (area_2 > area || (area_2 == area && corr_sum > sum))
						corr_sum = sum;
					area = area_2;
				}
				else
					break;
			}
		}

	long long int* num = (long long int*)calloc(sizeof(int), 2);
	num[0] = area;
	num[1] = corr_sum;
	return num;
}

int main(){
	int num = 0; 
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%lld %lld %lld", &n, &m, &k);
		
		for(long long int j = 0; j <= n; j++){
			for (long long int k = 0; k <= m; k++){
				if (j == 0 || k == 0)
					matrix[j][k] = 0;
				else{
					long long int left, up, pre = 0;
					long long int temp = 0;
					scanf("%lld", &temp);
					pre = matrix[j-1][k-1];
					up = matrix[j-1][k];
					left = matrix[j][k-1];
					matrix[j][k] = temp + left + up - pre;
				}
			}
		}
		long long int area = 0;
		long long int sum = INT_MAX;
		for (int j = 0; j < n ; j++)
			for (int k = 0; k < m; k++){
				long long int* num2 = find_area(j, k);
				if (num2[0] >= area){
					if (num2[0] >  area || (num2[0] == area && num2[1] < sum))
						sum = num2[1];
					area = num2[0];
				}
				free(num2);
			}
		if (sum == INT_MAX)
			sum = 0;
		printf("Case #%d: %lld %lld\n", i + 1, area, sum);
	}

	return 0;
}
