#include <bits/stdc++.h>
using namespace std;

int n;
int graph[100][100];
bool visited[100][100];
int color;

struct point {
	int y, x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool is_in_range(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < n);
}

int bfs_identify(int y, int x) {
	if (visited[y][x])
		return 0;
	if (graph[y][x] == 0) {
		visited[y][x] = true;
		return 0;
	}
	queue<point> q;
	q.push({ y, x });
	visited[y][x] = true;
	graph[y][x] = ++color;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (!is_in_range(cy, cx) || visited[cy][cx] || !graph[cy][cx])
				continue;

			q.push({ cy, cx });
			visited[cy][cx] = true;
			graph[cy][cx] = color;
		}
	}
	return 1;
}

struct point_cnt {
	int y, x, cnt;
};

bool is_edge(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];
		if (!is_in_range(cy, cx))
			continue;
		if (graph[cy][cx] == 0)
			return true;
	}
	return false;
}

int bfs_calculate(int y, int x) {
	int cur_color = graph[y][x];
	queue<point_cnt> q;
	visited[y][x] = true;
	q.push({ y, x, 0 });

	while (!q.empty()) {
		point_cnt cur = q.front();
		q.pop();

		if (graph[cur.y][cur.x] != 0 && graph[cur.y][cur.x] != cur_color) {
			return cur.cnt - 1;
		}

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx]) {
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
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			bfs_identify(i, j);

	int min_distance = INT_MAX;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] && is_edge(i, j)) {
				memset(visited, false, sizeof(visited));
				min_distance = min(min_distance, bfs_calculate(i, j));
			}
		}
	}
	cout << min_distance;
}