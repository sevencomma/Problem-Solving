#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N, M, ans;
char board[501][501];
int cache[501][501];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

// 0: fail, 1: success, 2: unchecked
int dp(int y, int x) {
	if (cache[y][x] == 2) return 0;

	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = 2;

	int dir;
	if (board[y][x] == 'U') dir = 0;
	else if (board[y][x] == 'L') dir = 1;
	else if (board[y][x] == 'D') dir = 2;
	else  dir = 3;

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (!is_in_range(ny, nx)) ret = 1;
	else {
		ret = min(ret, dp(ny, nx));
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (dp(i, j) == 1)
				ans++;
	cout << ans;
}