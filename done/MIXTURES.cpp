#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX_INT 1000000


using namespace std;
int memo[100][100];

int mixtures[100];
int size; 

int colorSum(int i, int j) {
    int ret = 0; 
    for (int k = i; k <= j; ++k) {
        ret += mixtures[k];
        ret %= 100; 
    }

    return ret; 
}


int dp(int i, int j) {

    if (memo[i][j] != -1) return memo[i][j]; 
    
    if (i == j) return 0; 

    int ret = MAX_INT; 
    for (int k = i; k < j; ++k) {
        int tmp = dp(i, k) + dp(k + 1, j) + colorSum(i,k)*colorSum(k + 1, j); 
        if (ret > tmp) {
            ret = tmp; 
        }
    }

    return memo[i][j] = ret; 
}


int main() {

    while(cin>>size) {
        for (int i = 0; i < size; ++i) {
            scanf("%d", &mixtures[i]); 
        }
        memset(memo, -1, sizeof(int) * 100 * 100);
        cout << dp(0, size - 1) << endl; 
    }
}
