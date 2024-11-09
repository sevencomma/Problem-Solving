#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, mod, cnt;
};	// mod --> 0 : 아래, 1 : 앞, 2 : 위, 3 : 뒤, 4 : 왼, 5 : 오른
	// dir --> 0 : 위, 1 : 왼, 2 : 아래, 3 : 오른
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M, sy, sx, ty, tx;

char board[500][500];
bool visited[500][500][6];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int move(int dir, int mod) {
	switch (dir) {
	case 0:
		switch (mod) {
		case 0: return 3;
		case 1: return 0;
		case 2: return 1;
		case 3: return 2;
		case 4: return 4;
		case 5: return 5;
		}
	case 1:
		switch (mod) {
		case 0: return 5;
		case 1: return 1;
		case 2: return 4;
		case 3: return 3;
		case 4: return 0;
		case 5: return 2;
		}
	case 2:
		switch (mod) {
		case 0: return 1;
		case 1: return 2;
		case 2: return 3;
		case 3: return 0;
		case 4: return 4;
		case 5: return 5;
		}
	case 3:
		switch (mod) {
		case 0: return 4;
		case 1: return 1;
		case 2: return 5;
		case 3: return 3;
		case 4: return 2;
		case 5: return 0;
		}
	}
	return -1;
}

int bfs() {
	queue<point> q;
	q.push({ sy, sx, 0, 0 });
	visited[sy][sx][0] = true;
	for (int i = 1; i < 6; i++)
		visited[ty][tx][i] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.y == ty && cur.x == tx && cur.mod == 0)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];
			
			if (!is_in_range(cy, cx) || board[cy][cx] == '#') continue;
			int k = move(i, cur.mod);
			if (visited[cy][cx][k]) continue;

			q.push({ cy, cx, k, cur.cnt + 1 });
			visited[cy][cx][k] = true;
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'D')
				sy = i, sx = j;
			if (board[i][j] == 'R')
				ty = i, tx = j;
		}
	cout << bfs();
}