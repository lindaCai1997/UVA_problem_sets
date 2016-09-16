#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool comp(vector<int> first, vector<int> second){
	if (first[1] > second[1])
		return true;
	else if (first[1] < second[1])
		return false;
	else if (first[2] < second[2])
		return true;
	else if (first[2] > second[2])
		return false;
	return first[0] < second[0];
}

int main(){
	int num = 0; 
	scanf("%d\n", &num);
	char* line = NULL;
	size_t size = 0;
	for (int i = 0; i < num ; i++){
		int cons[105][11] = {0};
		vector<vector<int> > rank;
		bool active[105] = {false};
		int a, n, t = 0;
		char s = '\0';
		size = 0;
		while (getline(&line, &size, stdin) > 0){
			if (sscanf(line, "%d %d %d %c\n", &a, &n, &t, &s) != 4){
				break;
			}
			active[a-1] = true;
			if (s == 'C'){
				if (cons[a-1][n] <= 0){
					cons[a-1][0] += (t - cons[a-1][n]);
					cons[a-1][n] = 100;
					cons[a-1][10]++;
		//			printf("cons %d %d\n", a - 1, cons[a-1][10]);
				}
			}
			else if (s == 'I'){
				if (cons[a-1][n] <= 0)
					cons[a-1][n] -= 20;
			}
		}

		for (int j = 0; j < 100; j++){
			if (active[j] == true){
				vector<int> temp;
				temp.push_back(j + 1);
				temp.push_back(cons[j][10]);
				temp.push_back(cons[j][0]);	
				rank.push_back(temp);
			}
		}
		std::sort(rank.begin(), rank.end(), comp);
		for (int j = 0; j < rank.size(); j++){
			printf("%d %d %d\n", rank[j][0], rank[j][1], rank[j][2]);
		}
		if (i < num - 1)
			printf("\n");

	}
	return 0;



}
