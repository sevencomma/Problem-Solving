#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> sub;
int dp[20001], pos, N;

int solution(vector<string> strs, string t)
{
    for (auto& it : strs)
        if (t.find(it) != string::npos)
            sub[it] = true;
    N = t.length();
    
    for (int i = 1; i <= N; i++) {
        for (int j = 5; j > 0; j--) {
            pos = i - j;
            if (pos < 0 || dp[pos] == -1 || !sub[t.substr(pos, j)])
                continue;
            if (dp[i] == 0)
                dp[i] = dp[pos] + 1;
            else
                dp[i] = min(dp[i], dp[pos] + 1);
        }
        if (dp[i] == 0)
            dp[i] = -1;
    }
    
    if (dp[N] == 0)
        return -1;
    return dp[N];
}