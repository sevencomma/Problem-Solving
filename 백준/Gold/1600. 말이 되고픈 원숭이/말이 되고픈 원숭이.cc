#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, horse, cnt;
};

int H, W, K;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int dhy[8] = { -1,-2,-2,-1,1,2,2,1 };
int dhx[8] = { -2,-1,1,2,2,1,-1,-2 };

char board[200][200];
bool visited[200][200][31];

bool is_in_range(int y, int x) {
	return y >= 0 && y < H && x >= 0 && x < W;
}

int bfs() {
	queue<point> q;
	q.push({ 0, 0, 0, 0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.y == H - 1 && cur.x == W - 1)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx][cur.horse] && board[cy][cx] != '1') {
				q.push({ cy, cx, cur.horse, cur.cnt + 1 });
				visited[cy][cx][cur.horse] = true;
			}
		}

		if (cur.horse < K) {
			for (int i = 0; i < 8; i++) {
				int cy = cur.y + dhy[i];
				int cx = cur.x + dhx[i];

				if (is_in_range(cy, cx) && !visited[cy][cx][cur.horse + 1] && board[cy][cx] != '1') {
					q.push({ cy, cx, cur.horse + 1, cur.cnt + 1 });
					visited[cy][cx][cur.horse + 1] = true;
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K >> W >> H;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			cin >> board[y][x];
	cout << bfs();
}