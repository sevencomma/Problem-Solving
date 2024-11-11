#include <bits/stdc++.h>
using namespace std;

int n;
int dp[301][2];
int seq[301];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	if (n == 1) {
		cout << seq[0];
		return 0;
	}
	dp[0][0] = seq[0];
	dp[1][0] = seq[1];
	dp[1][1] = seq[0] + seq[1];
	for (int i = 2; i < n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + seq[i];
		dp[i][1] = dp[i - 1][0] + seq[i];
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]);
}