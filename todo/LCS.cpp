#include <iostream>
#include <vector>
#include <cstring>

#define ENDL '$' 

using namespace std;

int N; 
string s1;
string s2; 

typedef struct node {
    char elem; 
    vector<struct node> childrens;
} SuffixTrie;

SuffixTrie *buildTrie(int pos) {
    SuffixTrie *sf = new SuffixTrie(); 
    if (pos == N) {
        sf->elem = ENDL; 
    }
}
