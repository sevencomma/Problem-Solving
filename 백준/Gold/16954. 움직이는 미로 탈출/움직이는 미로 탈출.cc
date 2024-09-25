#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, time;
};

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool is_in_range(int y, int x) {
	return y >= 0 && y < 8 && x >= 0 && x < 8;
}
char board[8][8];
bool wall_time[8][8][8];
bool visited[8][8][8];
// 7,0 --> 0,7

int bfs() {
	queue<point> q;
	q.push({ 7, 0, 0});
	visited[7][0][0] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.time >= 7)
			return 1;
		if (cur.y == 0 && cur.x == 7)
			return 1;

		for (int i = 0; i < 8; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx][cur.time + 1]) {
				if (!wall_time[cy][cx][cur.time] && !wall_time[cy][cx][cur.time + 1]) {
					q.push({ cy, cx, cur.time + 1 });
					visited[cy][cx][cur.time + 1] = true;
				}
			}
		}
		if (!wall_time[cur.y][cur.x][cur.time + 1])
			q.push({ cur.y, cur.x, cur.time + 1 });
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> board[i][j];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == '#')
				for (int k = i; k < 8; k++)
					wall_time[k][j][k - i] = true;

	cout << bfs();
}