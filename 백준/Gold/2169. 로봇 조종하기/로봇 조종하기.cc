#include <bits/stdc++.h>
using namespace std;

#define N_INF -987654321

int dy[4] = { 0, 1, 0 };
int dx[4] = { -1, 0, 1 };

int N, M;
int board[1000][1000];
int cache[1000][1000][3];
bool visited[1000][1000];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int dp_dfs(int y, int x, int dir) {
	if (y == N - 1 && x == M - 1)
		return board[y][x];
	int& ret = cache[y][x][dir];
	if (ret != N_INF) return ret;

	ret = N_INF;
	visited[y][x] = true;
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (is_in_range(ny, nx) && !visited[ny][nx]) {
			ret = max(ret, dp_dfs(ny, nx, i) + board[y][x]);
		}
	}
	visited[y][x] = false;

	return ret;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = N_INF;

	cout << dp_dfs(0, 0, 0) << '\n';
}