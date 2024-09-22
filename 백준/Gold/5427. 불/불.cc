#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int R, C;
char board[1001][1001];
int fire_time[1001][1001];
bool visited[1001][1001];

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

int bfs(int y, int x) {
	queue<point> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (!is_in_range(cy, cx))
				return cur.cnt + 1;
			if (!visited[cy][cx] && board[cy][cx] == '.' && fire_time[cy][cx] > cur.cnt + 1) {
				q.push({ cy, cx, cur.cnt + 1 });
				visited[cy][cx] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		memset(visited, false, sizeof(visited));
		cin >> C >> R;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> board[i][j];
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				fire_time[i][j] = INT_MAX;
		int s_y, s_x;
		vector<point> fire;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if (board[i][j] == '*')
					fire.push_back({ i, j, 0 });
				if (board[i][j] == '@')
					s_y = i, s_x = j;
			}

		queue<point> q;
		for (auto& it : fire) {
			q.push({ it.y, it.x, it.cnt });
			visited[it.y][it.x] = true;
		}
		while (!q.empty()) {
			point cur = q.front();
			q.pop();
			fire_time[cur.y][cur.x] = cur.cnt;
			for (int i = 0; i < 4; i++) {
				int cy = cur.y + dy[i];
				int cx = cur.x + dx[i];

				if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx] != '#') {
					q.push({ cy, cx, cur.cnt + 1 });
					visited[cy][cx] = true;
				}
			}
		}
		memset(visited, false, sizeof(visited));
		int res = bfs(s_y, s_x);
		if (res == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << res << '\n';
	}
}