#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, dir, cnt;
};

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int M, N, sy, sx, sd, ty, tx, td;
char board[100][100];
bool visited[100][100][5];

bool is_in_range(int y, int x) {
	return y >= 0 && y < M && x >= 0 && x < N;
}

int bfs() {
	queue<point> q;
	q.push({ sy-1, sx-1, sd, 0 });
	visited[sy][sx][sd] = true;
	
	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.y == ty-1 && cur.x == tx-1 && cur.dir == td)
			return cur.cnt;

		for (int i = 0; i < 2; i++) {
			if (cur.dir <= 2) {
				int k = 2;
				if (!visited[cur.y][cur.x][k + i]) {
					q.push({ cur.y, cur.x, k + i + 1, cur.cnt + 1 });
					visited[cur.y][cur.x][k + i] = true;
				}
			}
			else {
				if (!visited[cur.y][cur.x][i]) {
					q.push({ cur.y, cur.x, i + 1, cur.cnt + 1 });
					visited[cur.y][cur.x][i] = true;
				}
			}
		}
		for (int j = 1; j <= 3; j++) {
			int cy = cur.y + dy[cur.dir - 1] * j;
			int cx = cur.x + dx[cur.dir - 1] * j;

			if (is_in_range(cy, cx) && board[cy][cx] == '0') {
				if (!visited[cy][cx][cur.dir - 1]) {
					q.push({ cy, cx, cur.dir, cur.cnt + 1 });
					visited[cy][cx][cur.dir - 1] = true;
				}
			}
			else
				break;
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	cin >> sy >> sx >> sd >> ty >> tx >> td;
	cout << bfs();
}