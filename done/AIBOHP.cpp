#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


char input[6101]; 

int dp[6101][6101];
int solve(int i, int j) {

    if (dp[i][j] != -1) return dp[i][j]; 

    if (i >= j) {
        return 0; 
    }

    if (input[i] == input[j]) {
        return dp[i][j] = solve(i + 1, j - 1); 
    }

    int ret1 = solve(i + 1, j) + 1; 
    int ret2 = solve(i, j - 1) + 1; 

    return dp[i][j] = min(ret1, ret2); 
}



int main() {

    int cases;
    cin >> cases;

    for (; cases > 0; --cases) {
        scanf("%s\n", input); 
        int size = strlen(input); 
        memset(dp, -1, sizeof(int) * 6101 * 6101); 
        cout << solve(0, size - 1) << endl; 
    }
}
