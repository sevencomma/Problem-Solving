#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M, H, W, sy, sx, ly, lx;
char board[1001][1001];
bool visited[1001][1001];

bool is_in_range(int y, int x) {
	return y >= 0 && y <= N - H && x >= 0 && x <= M - W;
}

int bfs() {
	queue<point> q;
	q.push({ sy - 1, sx - 1, 0 });
	visited[sy - 1][sx - 1] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.y == ly - 1 && cur.x == lx - 1)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx]) {
				bool can = true;
				if (i % 4 == 0) {
					for (int j = 0; j < W; j++)
						if (board[cy][cx + j] == '1')
							can = false;
				}
				else if (i % 4 == 1) {
					for (int j = 0; j < H; j++)
						if (board[cy + j][cx] == '1')
							can = false;
				}
				else if (i % 4 == 2) {
					for (int j = 0; j < W; j++)
						if (board[cy + H - 1][cx + j] == '1')
							can = false;
				}
				else if (i % 4 == 3) {
					for (int j = 0; j < H; j++)
						if (board[cy + j][cx + W - 1] == '1')
							can = false;
				}
				if (can) {
					q.push({ cy, cx, cur.cnt + 1 });
					visited[cy][cx] = true;
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	cin >> H >> W >> sy >> sx >> ly >> lx;
	for (int i = sy - 1; i < sy + H - 1; i++)
		for (int j = sx - 1; j < sx + W - 1; j++)
			if (board[i][j] == '1') {
				cout << -1;
				return 0;
			}
	cout << bfs();
}