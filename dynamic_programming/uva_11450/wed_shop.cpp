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
int price[25][25] = {0};
int memo[201][25] = {-1};
int m, c;
int select(int money, int type){
	if (money < 0)
		return INT_MAX;
	if (type == c){
		if (money < 0)
			return INT_MAX;
		else
			return money;
	}
	if (memo[money][type] != -1)
		return memo[money][type];

	int i = 0;
	int min = INT_MAX;
	while(price[type][i] != 0){
		int left = select(money - price[type][i], type + 1);
		if (left < min)
			min = left;
		i++;
	}
	memo[money][type] = min;
	return min;
}	

int main(){
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		for (int j = 0; j < 25; j++)
			for (int k = 0; k < 25; k++)
				price[j][k] = 0;

		for (int j = 0; j < 201; j++)
			for (int k = 0; k < 25; k++)
				memo[j][k] = -1;
		scanf("%d %d", &m, &c);
		for (int j = 0; j < c; j++){
			int size = 0;
			scanf("%d", &size);
			for (int k = 0; k < size; k++)
				scanf("%d", &price[j][k]);	
		}
		int remain = select(m, 0);
		if (remain == INT_MAX)
			printf("no solution\n");
		else
			printf("%d\n", m - remain);

	}

	return 0;
}
