#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* a function to add another test case with random data
 * usage ./program filename
 */
int main(int argc, char* argv[]){
	FILE* file = fopen(argv[1], "a+");
	int money = rand() % 200;
	int types = rand() % 20;
	fprintf(file, "%d %d\n", money, types);
	for (int i = 0; i < types; i++){
		int model = rand() % 20;
		fprintf(file, "%d ", model);
		for (int j = 0; j < model; j++)
			fprintf(file, "%d ", rand() % 11 + 1);
		fprintf(file, "\n");
	}
	fclose(file);
	return 0;
}
