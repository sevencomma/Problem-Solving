#include <bits/stdc++.h>
using namespace std;

struct point {
	int  y, x, time;
	int type;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M, sy1, sx1, sy2, sx2;
int v1, v2, v3;
int board[1000][1000];
int vir_time[1000][1000];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void bfs() {
	queue<point> q;
	q.push({ sy1, sx1, 0, 1 });
	q.push({ sy2, sx2, 0, 2 });
	vir_time[sy1][sx1] = 0;
	vir_time[sy2][sx2] = 0;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		
		if (board[cur.y][cur.x] == 3)
			continue;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (!is_in_range(cy, cx) || board[cy][cx] == -1 || board[cy][cx] == 3)
				continue;

			if (board[cy][cx] == 0) {
				q.push({ cy, cx, cur.time + 1, cur.type });
				board[cy][cx] = cur.type;
				vir_time[cy][cx] = cur.time + 1;
			}
			else {
				if (board[cy][cx] != cur.type) {
					if (vir_time[cy][cx] == cur.time + 1)
						board[cy][cx] = 3;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			vir_time[i][j] = INT_MAX;
			cin >> board[i][j];
			if (board[i][j] == 1)
				sy1 = i, sx1 = j;
			else if (board[i][j] == 2)
				sy2 = i, sx2 = j;
		}
	bfs();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1)
				v1++;
			else if (board[i][j] == 2)
				v2++;
			else if (board[i][j] == 3)
				v3++;
		}
	cout << v1 << ' ' << v2 << ' ' << v3;
}