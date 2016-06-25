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
	int len = 0;
	while(scanf("%d", &len) > 0){
		if (len == 0)
			exit(0);
		int bet[10000] = {0};
		int min[10000] = {INT_MAX};
		int temp = 0;
		bet[0] = 0;
		for (int i = 1; i <= len; i++){
			scanf("%d", &temp);
			bet[i] = bet[i-1] + temp;
			if (min[i - 1] > bet[i])
				min[i] = bet[i];
			else
				min[i] = min[i-1];
		}
		int sum = 0;
		int max_sum = INT_MIN;
		for (int i = 1; i <= len; i++){
			if (max_sum < bet[i] - min[i])
				max_sum = bet[i] - min[i];
		}
		if (max_sum > 0)
			printf("The maximum winning streak is %d.\n", max_sum);
		else
			printf("Losing streak.\n");	
	}
	return 0;
}
