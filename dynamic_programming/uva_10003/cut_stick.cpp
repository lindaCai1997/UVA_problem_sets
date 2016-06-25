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
int matrix[52][52] = {0};
int cut[52] = {0};
int find_min_cost(int lo, int hi){
	if (lo >= hi)
		return 0;
	else if (lo == hi - 1)
		return 0;
	else if(matrix[lo][hi] > 0)
		return matrix[lo][hi];
	int min = INT_MAX;
	int sum = cut[hi] - cut[lo];
	for (int i = lo + 1; i < hi; i++){
		int first = find_min_cost(lo, i);
		int second = find_min_cost(i, hi);
		if (first + second < min)
			min = first + second;
	}
	matrix[lo][hi] = sum + min;
	return sum + min;
}

int main(){
	int l = 0;
	while( scanf("%d", &l) > 0){
		if (l == 0)
			exit(0);
		for (int i = 0; i < 52; i++){
			cut[i] = 0;
			for(int j = 0; j < 52; j++)
				matrix[i][j] = 0;
		}
		int len = 0;
		scanf("%d", &len);
		cut[0]  = 0;
		for (int i = 1; i <= len; i++){
			scanf("%d", &cut[i]);
		}
		cut[len + 1] = l;
		int sum = find_min_cost(0, len + 1);
		printf("The minimum cutting is %d.\n", sum);
	}
	return 0;
}
