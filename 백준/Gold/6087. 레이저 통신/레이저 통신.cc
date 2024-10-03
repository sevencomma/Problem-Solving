#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, dir, cnt;
};

struct cmp {
	bool operator() (point a, point b) const {
		return a.cnt > b.cnt;
	}
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int W, H;
char board[100][100];
int visited[100][100][4];

bool is_in_range(int y, int x) {
	return y >= 0 && y < H && x >= 0 && x < W;
}

int bfs(int y, int x) {
	priority_queue<point, vector<point>, cmp> q;
	q.push({ y, x, -1, 0 });
	for (int i = 0; i < 4; i++)
		visited[y][x][i] = 0;

	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		if (board[cur.y][cur.x] == 'C' && (cur.y != y || cur.x != x))
			return cur.cnt - 1;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && board[cy][cx] != '*') {
				if (cur.dir != i) {
					if (visited[cy][cx][i] > cur.cnt + 1) {
						q.push({ cy, cx, i, cur.cnt + 1 });
						visited[cy][cx][i] = cur.cnt + 1;
					}
				}
				else {
					if (visited[cy][cx][i] > cur.cnt) {
						q.push({ cy, cx, i, cur.cnt });
						visited[cy][cx][i] = cur.cnt;
					}
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> W >> H;
	int sy, sx;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C')
				sy = i, sx = j;
		}
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			for (int k = 0; k < 4; k++)
				visited[i][j][k] = INT_MAX;
	cout << bfs(sy, sx);
}