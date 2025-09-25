#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N, M;
char board[50][50];
int cache[50][50];
bool visited[50][50];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int dfs(int y, int x) {
	if (!is_in_range(y, x) || board[y][x] == 'H') return 0;
	if (visited[y][x]) {
		cout << -1;
		exit(0);
	}

	int& ret = cache[y][x];
	if (ret != -1) return ret;
	visited[y][x] = true;
	int d = board[y][x] - '0';

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * d;
		int nx = x + dx[i] * d;
		ret = max(ret, dfs(ny, nx) + 1);
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

	memset(cache, -1, sizeof(cache));
	cout << dfs(0, 0);
}