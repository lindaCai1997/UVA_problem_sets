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
/*
struct node{
	char op; 
	node* left;
	node* right;
};
*/
int main(){
	int num = 0; 
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		int l, m;
		bool dir_left = true;
	   	int count = 0;	
		int last_f = 0;
		scanf("%d %d\n", &l, &m);
		l = l*100;
		vector<int> left;
		vector<int> right;
		for (int j = 0; j < m; j++){
			char curr[5] = {0};
			int len;
			scanf("%d %s", &len, curr);
			if (strcmp(curr, "left") == 0)
				left.push_back(len);
			else
				right.push_back(len);
		}
		int le = 0;
		int ri = 0;
		int storage = l;
		while (le < left.size() || ri < right.size()){
			if (dir_left == true){
				if (le < left.size() && storage - left[le] >= 0)
					storage -= left[le++];
				else{
					storage = l;
					dir_left = false;
					count++;
				}
			}	
			else{
				if (ri < right.size() && storage - right[ri] >= 0)
					storage -= right[ri++];
				else{
					storage = l;
					dir_left = true;
					count++;
				}
			}	

		}
		if (storage < l)
			count++;
		printf("%d\n", count);

	}
	return 0;
}
	
