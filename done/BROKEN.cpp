#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

#include <bitset>

using namespace std;

int size; 
int nChar; 

char *input = NULL;
map<char,int> mapChar; 



int solve() {
    
    int i = 0;
    int j = 1; 

    mapChar[input[i]] = 1; 

    int maxSeq = 1; 
    int usedChar = 1; 
    while (j < size - 1) {
        int currentSeq = j - i; 
        while (j < size - 1) {
            if (mapChar[input[j]] == 0) {
                if (usedChar == nChar) break; 
                ++usedChar; 
            }
            ++mapChar[input[j]];
            ++currentSeq; 
            ++j; 
        }

        maxSeq = max(maxSeq, currentSeq); 
        --mapChar[input[i]]; 
        if (mapChar[input[i]] == 0) {
            --usedChar; 
        } 
        ++i; 
    }

    return maxSeq; 
}

int main() {


    size_t n; 
    while (scanf("%d\n", &nChar)) {
        if (nChar == 0) break; 
        getline(&input, &n, stdin); 
        size = strlen(input); 
        input[size - 1] = '\0'; 
        for (int i = 0; i < size - 1; ++i) {
            mapChar[input[i]] = 0; 
        }
        cout << solve() << endl; 
    }
}
