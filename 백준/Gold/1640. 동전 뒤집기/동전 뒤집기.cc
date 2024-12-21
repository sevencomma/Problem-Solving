#include <bits/stdc++.h>
using namespace std;

int rows[1000];
int cols[1000];
char board[1000][1000];
int N, M, row_one, col_one;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '1')
				rows[i]++, cols[j]++;
		}
	for (int i = 0; i < N; i++)
		if (rows[i] % 2)
			row_one++;
	for (int j = 0; j < M; j++)
		if (cols[j] % 2)
			col_one++;

	if (row_one % 2 != col_one % 2) {
		cout << -1;
		return 0;
	}

	if (row_one % 2 && col_one % 2) {
		int res = INT_MAX, tr, tc;

		if (row_one + 1 < N) {
			tr = (row_one + 1), tc = M - col_one;
			res = min(res, min(tr + tc, N + M - (tr + tc)));
		}
		tr = row_one - 1, tc = M - col_one;
		res = min(res, min(tr + tc, N + M - (tr + tc)));

		if (col_one + 1 < M) {
			tr = N - row_one, tc = (col_one + 1);
			res = min(res, min(tr + tc, N + M - (tr + tc)));
		}
		tr = N - row_one, tc = col_one - 1;
		res = min(res, min(tr + tc, N + M - (tr + tc)));

		cout << 1 + res;
	}
	else
		cout << min(row_one + col_one, N + M - (row_one + col_one));
}