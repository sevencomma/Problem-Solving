#include <bits/stdc++.h>
using namespace std;

int N, M, res;
char board[50][50];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int len = res + 1;
			while (1) {
				pair<int, int> R, D, DR;
				R = { i, j + len - 1 };
				D = { i + len - 1, j };
				DR = { i + len - 1, j + len - 1 };

				if (is_in_range(R.first, R.second) && is_in_range(D.first, D.second)
						&& is_in_range(DR.first, DR.second)) {
					if (board[i][j] == board[R.first][R.second] &&
						board[i][j] == board[D.first][D.second] &&
						board[i][j] == board[DR.first][DR.second])
						res = max(res, len);
				}
				else break;
				len++;
			}
		}
	cout << res * res;
}