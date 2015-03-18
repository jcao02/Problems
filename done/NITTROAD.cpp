#include <iostream>
#include <stdio.h>
#include <stack> 
#include <vector> 

using namespace std;

int N;
int parents[20001];
int ranks[20001];
int sizes[20001]; 
int removed[20001];


int find(int v) {

    if (parents[v] == v) {
        return v; 
    }

    int p = find(parents[v]); 
    parents[v] = p; 

    return p; 
}

void unify(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) return;

    if (ranks[pa] <= ranks[pb]) {
        sizes[pb] += sizes[pa]; 
        parents[pa] = pb;
        ++ranks[pb]; 
    } else {
        parents[pb] = pa;
        sizes[pa] += sizes[pb]; 
        ++ranks[pa]; 
    }
}


int main() {

    int cases;

    cin >> cases;
    vector< pair<int,int> > roads;

    for (; cases > 0; --cases) {
        scanf("%d", &N); 

        for(int i = 0; i < N + 1; ++i) {

            parents[i] = i;
            ranks[i]   = 0;
            sizes[i]   = 1;
            removed[i] = 0;
        }
        
        roads.clear();
        roads.reserve(N + 1); 
        roads.push_back(make_pair(0,0)); 

        for (int i = 1; i < N; ++i) {
            int first, second;
            scanf("%d %d", &first, &second);
            roads.push_back(make_pair(first, second)); 
        }

        int queries;
        scanf("%d", &queries); 
        getchar(); 
        stack<int> s; 

        char q; 
        int road; 

        for (int i = 0; i < queries; ++i) {
            scanf("%c", &q); 

            if (q == 'R') {
                scanf("%d", &road); 
                removed[road] = 1; 
            }
            s.push((q == 'Q' ? 0 : road));

            getchar(); 
        }

        for (int i = 1; i < N; ++i) {
            if (!removed[i]) {
                s.push(i); 
            }
        }
        
        stack<unsigned long long> results; 
        unsigned long long nPairs = (N * (N - 1)) / 2; 

        while (!s.empty()) {
            int cur = s.top(); 
            s.pop(); 

            if (cur == 0)  {
                results.push(nPairs);
            } else {
                int pa = find(roads[cur].first); 
                int pb = find(roads[cur].second); 
                nPairs -= sizes[pa] * sizes[pb]; 
                unify(roads[cur].first, roads[cur].second); 
            }
        }

        while (!results.empty()) {

            printf("%llu\n", results.top()); 
            results.pop(); 
        }

        if (cases > 1) cout << endl; 

    }
}
