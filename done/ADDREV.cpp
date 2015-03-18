#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char *reverse(char *s) {
    int N = strlen(s); 
    char *result = new char[N]; 
    int j = 0; 
    bool leadingZeros = true; 
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == '0' && leadingZeros) continue; 

        leadingZeros = false; 
        result[j] = s[i]; 
        ++j; 
    }

    result[j] = '\0';
    return result; 
}


int main() {


    int cases;
    cin >> cases;
    char first[256];
    char second[256];
    char result[256];

    for (; cases > 0; --cases) {
        scanf("%s %s", first, second);

        int fi = atoi(reverse(first));
        int si = atoi(reverse(second));

        int ri = fi + si; 

        sprintf(result, "%d", ri); 
        cout << reverse(result) << endl; 
    }
}
