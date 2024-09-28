#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, h;
};

struct cmp {
	bool operator() (point a, point b) {
		return a.h < b.h;
	}
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int M, N;
int board[500][500];
int visited[500][500];
int res = 0;

bool is_in_range(int y, int x) {
	return y >= 0 && y < M && x >= 0 && x < N;
}

void bfs(int y, int  x) {
	priority_queue<point, vector<point>, cmp> q;
	q.push({ y,x, board[y][x]});
	visited[y][x] = 1;

	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && board[cur.y][cur.x] > board[cy][cx]) {
				if (!visited[cy][cx]) {
					q.push({ cy,cx, board[cy][cx]});
				}
				visited[cy][cx] += visited[cur.y][cur.x];
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	bfs(0, 0);
	cout << visited[M - 1][N - 1];
}