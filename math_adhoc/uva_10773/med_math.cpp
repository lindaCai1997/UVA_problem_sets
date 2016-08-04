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
		double d, v, u;
		scanf("%lf %lf %lf", &d, &v, &u);
		double t1 = 0;
		double t2 = 0;
		bool print = true;
		if (u <= v || u == 0 || v == 0){
			printf("Case %d: can't determine\n", i + 1);
			print = false;
		}
		else {
			t1 = d/u;
			t2 = d/(sqrt(u*u - v*v));	
			printf("Case %d: %.3lf\n", i + 1, abs(t2 - t1));
		}
	}
	return 0;

}
