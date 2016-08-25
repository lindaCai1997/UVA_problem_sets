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

vector<int> seq;

void insert(int hi, int lo, int num){
	if (lo >= hi){
		seq[lo] = num;
		return;
	}
	int size = seq.size();
	int mid = (hi + lo)/2;
	if (num > seq[mid])
		insert(hi, mid + 1, num);
	else
		insert(mid, lo, num);
}

int main(){
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		int len = 0;
		scanf("%d", &len);
		int temp = 0;
		for (int j = 0; j < len; j++){
			scanf("%d", &temp);
			int size = seq.size();
			if (size == 0 || temp > seq[size - 1])
				seq.push_back(temp);
			else if (temp < seq[0])
				seq.insert(seq.begin(), temp);
			else
				insert(size - 1, 0, temp);
		}
		printf("%d\n", seq.size()); 		
		seq.clear();
	}
	return 0;
}
