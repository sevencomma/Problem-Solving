#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000009

long long dp[100001][4];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	dp[1][0] = dp[2][0] = 1;
	dp[3][0] = 3;
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		long long one, two, three;
		one = (MOD + dp[i - 1][0] - dp[i - 1][1]) % MOD;
		two = (MOD + dp[i - 2][0] - dp[i - 2][2]) % MOD;
		three = (MOD + dp[i - 3][0] - dp[i - 3][3]) % MOD;

		dp[i][0] = (one + two + three) % MOD;
		dp[i][1] = one, dp[i][2] = two, dp[i][3] = three;
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][0] << '\n';
	}
}