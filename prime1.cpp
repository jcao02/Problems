#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

void prime(long int m, long int n);

int main(int argc, const char *argv[])
{

    long int t, m, n;

    cin >> t;

    for (; t > 0; --t) {
    
        cin >> m;
        cin >> n;

        prime(m,n);

    }
    return 0;
}



void prime(long int m, long int n)
{
    bool *criba;
    long int p, i, j, t;

    t = n - m + 1;

    criba = (bool *)malloc(sizeof(bool)*t);

    /*Inicializacion*/
    for (i = 0; i < t; ++i)
        criba[i] = true;

    for ( i = 2; i * i < n; ++i ) {
        j = m / i;
        j *= i;
        for (; j <= n; j += i)
            if ( j != i  && j >= m ) {
                criba[j - m] = false;
            }

    }

    for (i = 0; i < t; ++i) {
        if (criba[i] && (m + i != 1)) {
            p = i + m;
            cout << p << endl;
        }
    }

    cout << endl;

}
