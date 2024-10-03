#include <bits/stdc++.h>
using namespace std;

struct point {
	int z, y, x, cnt;
};

int dz[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dx[6] = { 0, -1, 0, 1, 0, 0 };

int L, R, C;
char board[30][30][30];
bool visited[30][30][30];

bool is_in_range(int z, int y, int x) {
	return z >= 0 && z < L && y >= 0 && y < R && x >= 0 && x < C;
}

int bfs(int z, int y, int x) {
	queue<point> q;
	q.push({ z, y, x, 0 });
	visited[z][y][x] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (board[cur.z][cur.y][cur.x] == 'E')
			return cur.cnt;

		for (int i = 0; i < 6; i++) {
			int cz = cur.z + dz[i];
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cz, cy, cx) && !visited[cz][cy][cx] && board[cz][cy][cx] != '#') {
				q.push({ cz, cy, cx, cur.cnt + 1 });
				visited[cz][cy][cx] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> L >> R >> C;
		char temp;
		if (L == 0)
			break;
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		int sz, sy, sx;
		for (int z = 0; z < L; z++)
			for (int y = 0; y < R; y++)
				for (int x = 0; x < C; x++) {
					cin >> board[z][y][x];
					if (board[z][y][x] == 'S')
						sz = z, sy = y, sx = x;
				}
		int res = bfs(sz, sy, sx);
		if (res == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << res << " minute(s).\n";
	}
}