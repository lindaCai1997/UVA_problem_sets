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
    char* line = (char*)calloc(1000000, 1);
    char* line2 = (char*)calloc(1000000, 1);
    scanf("%s", line);
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%s", line2);
        int start = 0;
        int end = 0;
        int pos1 = 0;
        int pos2 = 0;
        bool match = false;
        while( line[pos1] != 0){
            if(line[pos1] == line2[pos2]){
                if (pos2 == 0)
                    start = pos1;
                pos2++;
            }
            if(line2[pos2] == '\0'){
                match = true;
                end = pos1;
                break;
            }
            pos1++;
        }
        if (match == false){
            printf("Not matched\n");
        }
        else
            printf("Matched %d %d\n", start, end);
    }
    return 0;

}
