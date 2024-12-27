#include <bits/stdc++.h>
using namespace std;

int dp[100000][4], res, N;

int solution(vector<vector<int> > land)
{
    for (int i = 0; i < 4; i++)
        dp[0][i] = land[0][i];
    N = land.size();
    
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                if (j == k)
                    continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + land[i][j]);
            }
    for (int i = 0; i < 4; i++)
        res = max(res, dp[N - 1][i]);
    return res;
}