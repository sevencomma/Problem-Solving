#include <bits/stdc++.h>
using namespace std;

int intersection(vector<int>& seq, vector<int>& q) {
    map<int, int> cnt;
    for (auto& it : seq)
        cnt[it]++;
    for (auto& it: q)
        cnt[it]++;
    
    int ret = 0;
    for (auto& it: cnt)
        if (it.second == 2)
            ret++;
    return ret;
}

bool solve(vector<int>& seq, vector<vector<int>>& q, vector<int>& ans) { 
    for (int i = 0; i < q.size(); i++)
        for (int j = 0; j < 5; j++)
            if (intersection(seq, q[i]) != ans[i])
                return false;
    
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<bool> visited(n, false);
    for (int i = 0; i < 5; i++)
        visited[i] = true;
    
    int res = 0;
    
    do {
        vector<int> seq;
        for (int i = 0; i < n; i++)
            if (visited[i])
                seq.push_back(i + 1);
        if (solve(seq, q, ans))
            res++;
        
    } while(prev_permutation(visited.begin(), visited.end()));
    
    return res;
}