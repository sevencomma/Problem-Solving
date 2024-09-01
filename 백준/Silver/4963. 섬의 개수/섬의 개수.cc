#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

bool is_in_range(int y, int x, int h, int w) {
	return (y >= 0 && y < h && x >= 0 && x < w);
}

bool visited[50][50] = { false };

int bfs(int y, int x, vector<vector<int>>& graph)
{
	if (visited[y][x])
		return 0;

	if (!graph[y][x]) {
		visited[y][x] = true;
		return 0;
	}

	queue<point> q;
	q.push({ y,x });
	visited[y][x] = true;
	
	while (!q.empty()) {
		point temp = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int cy = temp.y + dy[i];
			int cx = temp.x + dx[i];

			if (!is_in_range(cy, cx, graph.size(), graph[0].size()) || visited[cy][cx] || !graph[cy][cx])
				continue;

			q.push({ cy, cx });
			visited[cy][cx] = true;
		}
	}
	return 1;
}

int main(void)
{
	while (1) {
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		vector<vector<int>> graph(h);

		for (int i = 0; i < h; i++)
			graph[i].resize(w);

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> graph[i][j];

		memset(visited, false, sizeof(visited));
		int count = 0;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (bfs(i, j, graph) == 1)
					count++;

		cout << count << "\n";
	}
}