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
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int num = 0; 
		scanf("%d", &num);
		vector<int> list;
		int temp = 0;
		for (int j = 0; j < num; j++){
			scanf("%d", &temp);
			list.push_back(temp);
		}
		//std::sort(list.begin(), list.end());
		printf("Case %d: %d\n", i + 1, list[num/2]);
		
	}



}
