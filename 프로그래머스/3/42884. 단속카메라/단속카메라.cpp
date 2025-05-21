#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int res = 0;
    int N = routes.size();
    
    sort(routes.begin(), routes.end(), compare);
    int start = routes[0][0];
    int lastCheck = routes[0][1];
    res++;
    
    for (int idx = 1; idx < N; idx++) {
        start = routes[idx][0];
        
        if (start <= lastCheck)
            continue;
        
        lastCheck = routes[idx][1];
        res++;
    }
    
    return res;
}