#include <bits/stdc++.h>
using namespace std;

int N, M, K, res;
char board[2001][2001];
int prefixSum[2001][2001][2];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			prefixSum[i][j][0] = prefixSum[i - 1][j][0] + prefixSum[i][j - 1][0] - prefixSum[i - 1][j - 1][0];
			prefixSum[i][j][1] = prefixSum[i - 1][j][1] + prefixSum[i][j - 1][1] - prefixSum[i - 1][j - 1][1];

			if (board[i][j] == 'W') {
				if ((i + j) % 2 == 0)
					prefixSum[i][j][0]++;
				else
					prefixSum[i][j][1]++;
			}
			else {
				if ((i + j) % 2 == 0)
					prefixSum[i][j][1]++;
				else
					prefixSum[i][j][0]++;
			}
		}

	for (int y = 1; y <= N - K + 1; y++)
		for (int x = 1; x <= M - K + 1; x++) {
			for (int z = 0; z < 2; z++) {
				int cnt;
				// [i][j] : [i + K - 1][j + K - 1] + [i - 1][j - 1] - [i - 1][j] - [i][j - 1]
				cnt = prefixSum[y + K - 1][x + K - 1][z] + prefixSum[y - 1][x - 1][z]
					- prefixSum[y - 1][x + K - 1][z] - prefixSum[y + K - 1][x - 1][z];

				res = max(res, cnt);
			}
		}

	cout << K * K - res;
}