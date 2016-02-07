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
using namespace std;

int main(){
  //used a maps to store everyone's give and take of gift money
  //m0 is money given and m1 is money taken 
    map<string, int> m0;
    map<string, int> m1;
    
  //store all people's name
    string* ppl= new string[10];
    
    int pl = 0;
    bool isFirst = false;
    
    while (cin>>pl){
        if (isFirst)
            cout << endl;
        for (int i = 0; i < pl; i++){
            cin>>ppl[i];
            m0[ppl[i]] = 0;
            m1[ppl[i]] = 0;
        }
        string name, fname; int gift,num;

        for (int i = 0; i < pl; i++){
            cin >> name >> gift >> num;
            if (num != 0 ){
                m0[name] = gift - gift % num;
                for (int j = 0; j<num; j++){
                    cin >>fname;
                    m1[fname] += gift/num;
                }
            }

        }
        for (int i = 0; i < pl; i++){
            cout<<ppl[i]<<" "<<m1[ppl[i]] - m0[ppl[i]]<<endl;
        }

        isFirst = true;
        m0.clear();
        m1.clear();
    }

    return 0;
}
