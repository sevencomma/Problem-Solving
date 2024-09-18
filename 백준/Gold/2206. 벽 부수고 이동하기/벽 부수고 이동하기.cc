#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
	bool one_punch;
};
int n, m;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char board[1000][1000];
bool visited[1000][1000];
bool broken_visited[1000][1000];

bool is_in_range(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < m);
}

int bfs() {
	queue<point> q;
	q.push({ 0, 0, 1, false });
	visited[0][0] = true;
	broken_visited[0][0] = true;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.y == n - 1 && cur.x == m - 1)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (!is_in_range(cy, cx))
				continue;
			if (cur.one_punch && broken_visited[cy][cx])
				continue;
			if (!cur.one_punch && visited[cy][cx])
				continue;

			if (board[cy][cx] == '1' && cur.one_punch == false) {
				q.push({ cy, cx, cur.cnt + 1, true });
				broken_visited[cy][cx] = true;
				continue;
			}
			if (board[cy][cx] == '1')
				continue;
			q.push({ cy, cx, cur.cnt + 1, cur.one_punch });
			if (cur.one_punch)
				broken_visited[cy][cx] = true;
			else
				visited[cy][cx] = true;
		}
	}
	return -1;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	cout << bfs();
}