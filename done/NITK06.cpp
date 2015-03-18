#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;


int arr[10000];
int N; 

bool solve(int i) {
    
    if (i == N - 1) {
        if(arr[i] != 0) return false; 
        else return true; 
    }


    if (arr[i] > arr[i + 1]) 
        return false;

    if (arr[i] != 0) {
        arr[i + 1] -= arr[i];
        arr[i] = 0; 
    }

    return solve(i + 1); 
}

int main() {

    int cases;

    cin >> cases;
    
    for (; cases > 0; --cases) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &arr[i]); 
        }

        cout << (solve(0) ? "YES" : "NO") << endl; 
    }
}
