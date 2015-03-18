#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char code[5001] = ""; 
unsigned long long int comb[5001];
int size; 

void dp() {

    comb[0] = 1; 
    
    for (int i = 1; i < size; ++i) {

        if (code[i] != '0') {
            comb[i] = comb[i - 1];
        }
        if (code[i - 1] == '1') {
            if (i != 1) {comb[i] += comb[i - 2];}
            else {++comb[i];} 
        } else if (code[i - 1] == '2' && code[i] <= '6') {
            if (i != 1) {
                comb[i] += comb[i - 2];
            } else {
                ++comb[i];
            }
        }
    }

    printf("%llu\n",comb[size - 1]);
}

int main() {
    while (scanf("%s", code)) {
        if (strcmp(code,"0") == 0)
            break; 
        size = strlen(code); 
        memset(comb, 0, sizeof(unsigned long long int) * 5001);
        dp();
    }
}
