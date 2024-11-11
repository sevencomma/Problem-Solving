#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001][3];
int cost[1001][3];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	for (int i = 0; i < 3; i++)
		dp[0][i] = cost[0][i];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int n1 = (j + 1) % 3, n2 = (j + 2) % 3;
			dp[i][j] = min(dp[i - 1][n1], dp[i - 1][n2]) + cost[i][j];
		}
	}
	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}