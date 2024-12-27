#include <bits/stdc++.h>
using namespace std;

int dp1[1000000][2];    // 0 : on, 1 : off
int dp2[1000000][2];    // dp1[0][1] = NULL, dp2[0][0] = NULL;

int solution(vector<int> money) {
    int N = money.size();
    dp1[0][0] = money[0];
    
    for (int i = 1; i < N - 1; i++) {
        dp1[i][0] = dp1[i - 1][1] + money[i];
        dp1[i][1] = max(dp1[i - 1][0], dp1[i - 1][1]);
    }
    for (int i = 1; i < N; i++) {
        dp2[i][0] = dp2[i - 1][1] + money[i];
        dp2[i][1] = max(dp2[i - 1][0], dp2[i - 1][1]);
    }
    return max(max(dp1[N-2][0], dp1[N-2][1]), max(dp2[N-1][0], dp2[N-1][1]));
}