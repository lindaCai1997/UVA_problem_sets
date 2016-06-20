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
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		int len = 0;
		scanf("%d", &len);
		int* sum = (int*)calloc(sizeof(int), 20001);
		int nice = 0;
		for (int j = 0; j < len -1; j++){
			scanf("%d", &nice);
			sum[j + 1] = sum[j] + nice;
		}
		int min = INT_MAX;
		int min_idx = 0;
		int max_up = 0;
		int start = 0;
		int end = 0;
		for (int j = 0; j < len; j++){
			if (sum[j] < min){
				min = sum[j];
				min_idx = j;
			}
			if ((sum[j] - min > max_up) || 
					(sum[j] - min == max_up && j - min_idx > end - start)){
				max_up = sum[j] - min;
				start = min_idx;
				end = j;
			}	
		}
		if (max_up == 0)
			printf("Route %d has no nice parts\n", i + 1);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", i + 1, start + 1, end + 1);
		free(sum);
		sum = NULL;

	}
	return 0;
}
