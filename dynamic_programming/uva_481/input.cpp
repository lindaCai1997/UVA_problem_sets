#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	FILE* file = fopen("test3", "w+");
	for (int i = 0; i <100; i++){
		int a = rand() % 10000;
		fprintf(file, "%d ", a);
		if (i % 20 == 0)
			fprintf(file, "\n"); 
	}
	return 0;
}
