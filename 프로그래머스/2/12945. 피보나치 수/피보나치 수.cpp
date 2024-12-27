#include <bits/stdc++.h>
using namespace std;

#define MOD 1234567
int dp[100001];

int solution(int n) {
    dp[1] = dp[2] = 1;
    for (int i = 3; i<= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    return dp[n];
}