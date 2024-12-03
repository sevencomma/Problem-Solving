#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<int> setA;
unordered_set<int> setB;
vector<int> cntA;
vector<int> cntB;
int res;

int solution(vector<int> topping) {
    int N = topping.size();
    cntA.resize(N);
    cntB.resize(N);
    for (int i = 0; i < N; i++) {
        setA.insert(topping[i]);
        cntA[i] = setA.size();
        
        setB.insert(topping[N - 1 - i]);
        cntB[N - 1 - i] = setB.size();
    }
    
    for (int i = 1; i < N - 1; i++)
        if (cntA[i] == cntB[i + 1])
            res++;

    return res;
}