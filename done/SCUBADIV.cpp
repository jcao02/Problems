#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_W 800001

using namespace std;


typedef struct {
    int oxigen, nitrogen, weight; 
} cylinder ;

int nCyl; 


cylinder cyl[1001]; 

int dp[1001][22][80];


int solve(int O, int N) {

    for (int i = 0; i <= nCyl; ++i) {
        for (int j = 0; j < 22; ++j) {
            for (int k = 0; k < 80; ++k) {
                if (i == 0) {
                    dp[i][j][k] =  (j == 0 && k == 0 ? 0 : MAX_W); 
                } else {
                    dp[i][j][k] = min(dp[i - 1][j][k] ,
                            dp[i - 1][max(0, j - cyl[i].oxigen)][max(0, k - cyl[i].nitrogen)] + cyl[i].weight); 
                }
            }
        }
    }

    return dp[nCyl][O][N];
}

int main() {
    
    int c, o, n;

    cin >> c;

    for (; c > 0; --c) {
        scanf("%d %d", &o, &n); 
        scanf("%d", &nCyl); 

        for (int i = 1; i <= nCyl; ++i) {
            scanf("%d %d %d", &cyl[i].oxigen, &cyl[i].nitrogen, &cyl[i].weight); 
        }

        cout << solve(o, n) << endl; 
    }
}
