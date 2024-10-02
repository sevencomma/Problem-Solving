#include <bits/stdc++.h>
using namespace std;

struct point {
	int ry, rx, by, bx, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M;
char board[10][10];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(int ry, int rx, int by, int bx) {
	queue<point> q;
	q.push({ ry, rx, by, bx, 0 });
	
	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.cnt >= 10)
			return -1;

		for (int i = 0; i < 4; i++) {
			int cry = cur.ry;
			int crx = cur.rx;
			int cby = cur.by;
			int cbx = cur.bx;
			// red - > blue - > red 순서
			bool success = false;
			while (is_in_range(cry + dy[i], crx + dx[i]) && board[cry + dy[i]][crx + dx[i]] != '#' && (cry + dy[i] != cby || crx + dx[i] != cbx)) {
				cry += dy[i];
				crx += dx[i];
				if (board[cry][crx] == 'O') {
					cry = INT_MIN, crx = INT_MIN;
					success = true;
					continue;
				}
			}
			bool fail = false;
			while (is_in_range(cby + dy[i], cbx + dy[i]) && board[cby + dy[i]][cbx + dx[i]] != '#' && (cby + dy[i] != cry || cbx + dx[i] != crx)) {
				cby += dy[i];
				cbx += dx[i];
				if (board[cby][cbx] == 'O') {
					fail = true;
					continue;
				}
			}
			if (fail)
				continue;
			while (is_in_range(cry + dy[i], crx + dx[i]) && board[cry + dy[i]][crx + dx[i]] != '#' && (cry + dy[i] != cby || crx + dx[i] != cbx)) {
				cry += dy[i];
				crx += dx[i];
				if (board[cry][crx] == 'O')
					success = true;
			}
			if (cry == cur.ry && crx == cur.rx && cby == cur.by && cbx == cur.bx)
				continue;
			if (success)
				return cur.cnt + 1;
			q.push({ cry, crx, cby, cbx, cur.cnt + 1 });
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int ry, rx, by, bx;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R')
				ry = i, rx = j;
			if (board[i][j] == 'B')
				by = i, bx = j;
		}
	cout << bfs(ry, rx, by, bx);
}