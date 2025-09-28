#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N, M;
int board[100][100];
bool visited[100][100];

bool is_in_range(int y, int x) {
	return y >= 0 && y < M && x >= 0 && x < N;
}

bool bfs(vector<pair<int, int>> start, int a, int b, int c) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	for (auto& it : start) {
		q.push(it);
		visited[it.first][it.second] = true;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.first == M - 1)
			return true;

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (is_in_range(ny, nx) && !visited[ny][nx] && (board[ny][nx] == a ||
				board[ny][nx] == b || board[ny][nx] == c)) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	return false;
}

bool solve(int a, int b, int c) {
	vector<pair<int, int>> start;

	for (int i = 0; i < N; i++)
		if (board[0][i] == a || board[0][i] == b || board[0][i] == c)
			start.push_back({ 0, i });
	if (bfs(start, a, b, c))
		return true;
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < 10; i++)
		for (int j = i; j < 10; j++)
			for (int k = j; k < 10; k++) {
				if (solve(i, j, k)) {
					cout << i << ' ' << j << ' ' << k;
					return 0;
				}
			}
	cout << -1 << ' ' << -1 << ' ' << -1;
}