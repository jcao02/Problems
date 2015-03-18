#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>

using namespace std;

int N; 
int elems[500]; 

int A[1000001];
unordered_map<int, int> freqMap; 
int B[1000001];
int sizeA, sizeB; 


long long solve() {


    sizeA = 0; 
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            for (int c = 0; c < N; ++c) {
                A[sizeA++] = elems[a] * elems[b] + elems[c]; 
                ++freqMap[A[sizeA - 1]]; 
            }
        }
    }

    sizeB = 0;
    for (int d = 0; d < N; ++d) {
        if (elems[d] == 0) continue; 
        for (int e = 0; e < N; ++e) {
            for (int f = 0; f < N; ++f) {
                B[sizeB++] = (elems[f] + elems[e]) * elems[d]; 
            }
        }
    }

    long long ret = 0; 
    for (int i = 0; i < sizeB; ++i) {
        ret += freqMap[B[i]]; 
    }

    return ret; 
}

int main() {

    cin >> N; 

    for (int i = 0; i < N; ++i) {
        int elem; 
        scanf("%d", &elem);
        elems[i] = elem; 
    }

    cout << solve() << endl;  
}
