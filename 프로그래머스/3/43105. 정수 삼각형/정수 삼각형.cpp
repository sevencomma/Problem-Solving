#include <bits/stdc++.h>
using namespace std;

int dp[500][500], res;

int solution(vector<vector<int>> triangle) {
    int N = triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    for (int i = 0; i < N; i++)
        res = max(res, dp[N - 1][i]);
    return res;
}