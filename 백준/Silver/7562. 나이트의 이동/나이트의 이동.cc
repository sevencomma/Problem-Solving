#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int W;
bool visited[300][300] = { false };

bool is_in_range(int y, int x) {
	return (y >= 0 && y < W && x >= 0 && x < W);
}

int bfs(int sy, int sx, int ly, int lx) {
	queue<point> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx];

	while (!q.empty()) {
		point temp = q.front();
		q.pop();

		if (temp.y == ly && temp.x == lx)
			return temp.cnt;

		for (int i = 0; i < 8; i++) {
			int cy = temp.y + dy[i];
			int cx = temp.x + dx[i];

			if (!is_in_range(cy, cx) || visited[cy][cx])
				continue;

			q.push({ cy, cx, temp.cnt + 1 });
			visited[cy][cx] = true;
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> W;
		int s_y, s_x, l_y, l_x;
		memset(visited, false, sizeof(visited));

		cin >> s_y >> s_x >> l_y >> l_x;
		cout << bfs(s_y, s_x, l_y, l_x) << "\n";
	}
}