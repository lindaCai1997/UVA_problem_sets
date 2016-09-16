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
	int num = 0; 
	scanf("%d\n", &num);
	for (int i = 0; i < num; i++){
		char* numbers = (char*)calloc(300, 1);
		int n = 300;
		fgets(numbers, n, stdin);
		int len = strlen(numbers) - 1;
		numbers[len] = '\0';
		
		vector<long long int> sumup;

		long long int max_num = 0;
		for (int j = len - 1; j >= 0; j--){
			if (j == len - 1){
				char c = numbers[j];
				sumup.push_back((long long int)(c - '0'));
			}
			else{
				max_num = 0;
				long long int num1 = 0;
				long long int limit = INT_MAX;
				for (int k = 0; k < min(10, len - j - 1); k++){
					num1 = num1*10 + (long long int)(numbers[j + k] - '0');
					if (num1 <= limit && num1 + sumup[len - 1 - j - k - 1] > max_num){
						max_num = num1 + sumup[len - 2 - j - k];
					}
				}
				num1 = num1*10 + numbers[min(j + 10, len - 1)] - '0';
				if (num1 <= limit && num1 > max_num)
					max_num = num1;
				sumup.push_back(max_num);
			}
		}
		printf("%lld\n", max_num);

	}
	return 0;
}
