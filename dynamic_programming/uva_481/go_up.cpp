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
vector<int> true_seq;
vector<bool> flip;
void insert(int hi, int lo, int num){
	int size = seq.size();
	if (lo >= hi){
		seq[lo] = num;
		flip[lo] = false;
		if (lo == size - 1){
			while(lo >= 0 && flip[lo] == false){
				true_seq[lo] = seq[lo];
				flip[lo] = true;
				lo--;
			}
		}
		return;
	}	
	int mid = (hi + lo)/2;
	if (num > seq[mid])
		insert(hi, mid + 1, num);
	else
		insert(mid, lo, num);
}

int main(){
	int temp = 0;
	while(scanf("%d", &temp) > 0){
		int size = seq.size();
		if (size == 0 || temp > seq[size - 1]){
			seq.push_back(temp);
			true_seq.push_back(temp);
			flip.push_back(true);
		}
		else
			insert(size - 1, 0, temp);
	}
	int size = seq.size();
	printf("%d\n-\n", size);
	for(int i = 0; i < size; i++)
		printf("%d\n", true_seq[i]);
	return 0;
}
