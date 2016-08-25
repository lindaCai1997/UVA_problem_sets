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
	int i = 1;
	int r, n;
	while(scanf("%d %d", &r, &n) > 0){
		if (r == 0 && n == 0)
			exit(0);
		if (r > n*27)
			printf("Case %d: impossible\n", i);
		else{
			printf("Case %d: %d\n", i, (r - 1)/n);
		}
		i++;
	}
	return 0;

}
