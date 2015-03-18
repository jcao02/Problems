#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct {
    int start, end;
} act;

inline bool operator<(const act& lhs, const act& rhs) {
    return lhs.end < rhs.end; 
}

int main() {
    int cases;

    cin >> cases;

    vector<act> activities;
    for (; cases > 0; --cases) {

        int N; 
        scanf("%d", &N); 

        activities.clear();
        activities.reserve(N); 

        for (int i = 0; i < N; ++i) {
            act a;
            scanf("%d %d", &a.start, &a.end); 
            activities.push_back(a); 
        }

        sort(activities.begin(), activities.end());

        int lastEnd = -1; 
        int maxAct = 0; 
        for (int i = 0; i < N; ++i) {

            if (activities[i].start >= lastEnd) {
                ++maxAct;
                lastEnd = activities[i].end; 
            }
        }

        cout << maxAct << endl; 

    }
}
