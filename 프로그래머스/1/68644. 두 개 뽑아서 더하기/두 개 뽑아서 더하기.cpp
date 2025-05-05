#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    map<int, bool> X;
    
    int n = numbers.size();
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            X[numbers[i] + numbers[j]] = true;
    
    vector<int> ret;
    for(auto& it : X)
        ret.push_back(it.first);
    return ret;
}
