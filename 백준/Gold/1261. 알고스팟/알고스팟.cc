#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[100][100];
bool visited[100][100];

struct point {
	int y, x, cnt;
};
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0 ,-1, 0, 1 };

bool is_in_range(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}

struct cmp {
	bool operator() (point a, point b) const {
		return a.cnt > b.cnt;
	}
};

int bfs(point start) {
	priority_queue<point, vector<point>, cmp> q;
	q.push({ start.y, start.x, 0 });
	visited[start.y][start.x] = true;

	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		if (cur.y == N - 1 && cur.x == M - 1)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx]) {
				if (board[cy][cx] == '0')
					q.push({ cy,cx, cur.cnt });
				else
					q.push({ cy, cx, cur.cnt + 1 });
				visited[cy][cx] = true;
			}
		}
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	cout << bfs({ 0,0 });
}