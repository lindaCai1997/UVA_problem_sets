#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* a function to add test case with random data
 * usage ./program filename matrix_size
 */
int main(int argc, char* argv[]){
	FILE* file = fopen(argv[1], "w+");
	int size = atoi(argv[2]);
	fprintf(file, "%d\n", size);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			int num = rand() % 255 - 127;
			fprintf(file, "%d ", num);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	return 0;
}
