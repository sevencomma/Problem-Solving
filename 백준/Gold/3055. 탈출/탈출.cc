#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int R, C;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char board[51][51];
int water_time[51][51];
bool visited[51][51];

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

int bfs(int y, int x, int target_y, int target_x) {
	queue<point> q;
	q.push({ y, x, 0 });
	visited[y][x] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.y == target_y && cur.x == target_x)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx] != 'X' && water_time[cy][cx] > cur.cnt + 1) {
				q.push({ cy,cx, cur.cnt + 1 });
				visited[cy][cx] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];

	vector<point> water;
	int s_y, s_x;
	int d_y, d_x;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			water_time[i][j] = INT_MAX;
			if (board[i][j] == 'S')
				s_y = i, s_x = j;
			if (board[i][j] == 'D')
				d_y = i, d_x = j;
			if (board[i][j] == '*')
				water.push_back({ i,j, 0 });
		}

	queue<point> q;
	for (auto& it : water) {
		q.push(it);
		visited[it.y][it.x] = true;
	}
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		water_time[cur.y][cur.x] = cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx] != 'X' && board[cy][cx] != 'D') {
				q.push({ cy, cx, cur.cnt + 1 });
				visited[cy][cx] = true;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	int res = bfs(s_y, s_x, d_y, d_x);
	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res;
}