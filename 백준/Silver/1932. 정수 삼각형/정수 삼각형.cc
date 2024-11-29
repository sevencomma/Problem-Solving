#include <bits/stdc++.h>
using namespace std;

int N, res;
int board[500][500];
int dp[500][500];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> board[i][j];

	dp[0][0] = board[0][0];
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < i + 1; j++) {
			dp[i + 1][j] = max(board[i + 1][j] + dp[i][j], dp[i + 1][j]);
			dp[i + 1][j + 1] = max(board[i + 1][j + 1] + dp[i][j], dp[i + 1][j + 1]);
		}
	for (int i = 0; i < N; i++)
		res = max(res, dp[N - 1][i]);
	cout << res;
}