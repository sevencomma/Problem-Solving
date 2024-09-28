#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int n, m, k;
bool board[51][51];
bool visited[51][51];
bool is_in_range(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}

int bfs(int y, int x) {
	if (!board[y][x] || visited[y][x])
		return 0;

	queue<point> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx]) {
				q.push({ cy, cx });
				visited[cy][cx] = true;
			}
		}
	}
	return 1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		memset(board, false, sizeof(board));
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			board[b][a] = true;
		}
		memset(visited, false, sizeof(visited));
		int count = 0;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				count += bfs(y, x);
		cout << count << '\n';
	}
}