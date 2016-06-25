#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	FILE* file = fopen(argv[1], "w+");
	int many = atoi(argv[2]);
	for (int j = 0; j < many; j++){
		int len = atoi(argv[3 + j]);
		fprintf(file, "%d\n", len);
		for (int i = 0; i < len; i++){
			int num = rand() % 2000 - 1000;
			fprintf(file, "%d ", num);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "%d\n", 0);
	fclose(file);
	return 0;
}
