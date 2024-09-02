#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int n, m;
int graph[1000][1000] = { 0 };
bool visited[1000][1000] = { false };

bool is_in_range(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < m);
}

int bfs(vector<point>& start) {
	queue<point> q;

	for (auto& it : start) {
		q.push({ it.y, it.x, it.cnt });
		visited[it.y][it.x] = true;
	}

	int max = 0;
	while (!q.empty()) {
		point temp = q.front();
		q.pop();

		if (temp.cnt > max)
			max = temp.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = temp.y + dy[i];
			int cx = temp.x + dx[i];

			if (!is_in_range(cy, cx) || graph[cy][cx] != 0 || visited[cy][cx])
				continue;

			q.push({ cy, cx, temp.cnt + 1 });
			visited[cy][cx] = true;
		}
	}
	return max;
}

int main(void) {
	cin >> m >> n;
	vector<point> start;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				start.push_back({i, j, 0});
		}

	int res = bfs(start);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0 && visited[i][j] == false) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << res;
}