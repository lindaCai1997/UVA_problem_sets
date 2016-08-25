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
int matrix[27][27] = {0};
int edge = 0;
/*
int dfs(int num){
	if (num 
	for(int j = 0; j < 26; j++){
			if (matrix[26][j] == 0){
				temp_chars.push_back(j + 'A');	
				}
		}
	}	
}*/
vector<char> print(vector<char> chars, int n){
	size_t size = chars.size();
	for (int i = 0; i < chars.size(); i++)
		printf("%c ", chars[i]);
	n = n + 1;
	if (n % 2 != 0){
		std::swap(chars[size - 2], chars[size - 1]);
	}
	else if (n % 6 == 2){
		std::swap(chars[size - 3], chars[size - 1]);
		std::swap(chars[size - 2], chars[size - 1]);
	}
	else if (n % 6 == 4){
		std::swap(chars[size - 3], chars[size - 1]);
		std::swap(chars[size - 3], chars[size - 2]);
	}
	else if (n % 24 == 6){
		std::swap(chars[size - 3], chars[size - 1]);
		std::swap(chars[size - 3], chars[size - 4]);
	}
	else if (n % 24 == 12){
		std::swap(chars[size - 3], chars[size - 1]);
		std::swap(chars[size - 4], chars[size - 2]);
	}
	else if (n % 24 == 18){
		std::swap(chars[size - 3], chars[size - 1]);
		std::swap(chars[size - 4], chars[size - 1]);
	}
	else if (n % 120 == 24){
		std::swap(chars[size - 4], chars[size - 1]);
		std::swap(chars[size - 3], chars[size - 2]);
		std::swap(chars[size - 5], chars[size - 4]);
	}
	else if (n % 120 == 48){
		std::swap(chars[size - 3], chars[size - 2]);
		std::swap(chars[size - 5], chars[size - 3]);
		std::swap(chars[size - 4], chars[size - 1]);		
	}
	else if (n % 120 == 72){
		std::swap(chars[size - 3], chars[size - 2]);
		std::swap(chars[size - 5], chars[size - 2]);
		std::swap(chars[size - 4], chars[size - 1]);
	}
	else if (n % 120 == 96){
		std::swap(chars[size - 5], chars[size - 4]);
		std::swap(chars[size - 3], chars[size - 2]);
		std::swap(chars[size - 4], chars[size - 1]);
	
	}
	return chars;
}
int main(){
	vector<char> v;
	for (int i = 0; i < 5; i++)
		v.push_back('A' + i);
	for (int i = 0; i < 120; i++){
		v = print(v, i);
		printf("\n");
	}
	return 0;

}
/*
int main(){
	char* line = NULL;
	size_t w;
	getline(&line, &w, stdin);
	int n;
	sscanf(line,"%d", &n);
	for (int i = 0; i < n; i++){
		getline(&line, &w, stdin);
		getline(&line, &w, stdin);
		vector<char> chars;
		char temp;
		char temp2;
		while(sscanf(line,"%c", &temp) >= 1){
			chars.push_back(temp);
		}
		std::sort(chars);
		char matrix[27][27] = {0};
		
		int edge = 0;
		while(sscanf(line, "%c<%c", &temp, &temp2) >= 2){
			matrix[temp - 'A'][temp2 - 'A'] = 1;
			matrix[26][temp2 - 'A'] ++;
			edge ++;
		}
		vector<char>temp_chars;
		int size = chars.size();
	
		for(int j = 0; j < chars.size(); j++){
			if (matrix[26][chars[j] - 'A'] == 0){
				temp_chars.push_back(chars[j]);
				matrix[chars[j] - 'A'][26] = 1;
				size--;
			}
		}
		if (temp_chars.size() == 0){
			printf("NO\n");
			continue;
		}
	
		std::sort(temp_chars.begin(), temp_chars.end());
		order.push_back(temp_chars);
		temp_chars.clear();
		
	
		bool flag = true;
		while (size > 0){
			vector<char> curr = order.back();
			for(int j = 0; j < curr.size(); j++){
				for (int k = 0; k < 26; k++){
					if (matrix[curr[j] - 'A'][k] > 0){
						if (matrix[k][26] == 1){
							printf("NO\n");
							flag = false;
							break;
						}
						else{
							temp_chars.push_back('A' + k);
							matrix[k][26] = 1; 
							size--;
						}
					}
				}	
				if(flag == false)
					break;		
			}
			if(flag == false)
				break;
			std::sort(temp_chars);
			order.push_back(temp_chars);
			temp_chars.clear();
		}
		if (flag == true){
			for(int i = 0; i < order.size(); i++){
				vector<char> curr = order[i];
							
			}
		}	
			
	}

}*/
