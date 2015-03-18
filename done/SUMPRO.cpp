#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

unsigned long long pairs[32000]; // sqrt(10^9) = 31622
map<unsigned long long, unsigned long long> memo; 

unsigned long long solve(int N) {

    if (memo[N] != 0) return memo[N]; 
    unsigned long long result = 0; 
    unsigned long long SN = sqrt(N); 
    for (unsigned long long x = 1; x <= SN; ++x) {
        unsigned long long y = N / x; 
        unsigned long long z = y * x;
        result += z; 
        if (result >= 100000007)
            result %= 1000000007; 

        pairs[x] = y; 
   }

    pairs[SN + 1] = SN; 




    for (unsigned long long x = 1; x <= SN; ++x) {
        if (x != pairs[x]) {
            unsigned long long rest = (pairs[x + 1] + 1) - pairs[x] - 1; 
            unsigned long long add = pairs[x] + (pairs[x + 1] + 1); 
            unsigned long long sum = -(rest * add) / 2; 
            sum *= x; 
            result += sum; 
            if (result >= 100000007)
                result %= 1000000007; 
        }
    }

    memo[N] = result; 

    return result; 
}


int main() {

    int cases;

    cin >> cases;

    for (; cases > 0; --cases) {
        int N;
        scanf("%d", &N); 
        cout << solve(N) << endl; 
    }
}
