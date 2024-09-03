#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;

char graph[50][50];
bool visited[50][50] = { false };

bool is_in_range(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < m);
}

int dfs(point start) {
	stack<point> stack;
	stack.push(start);

	char color = graph[start.y][start.x];

	while (!stack.empty()) {
		point temp = stack.top();
		stack.pop();
		visited[temp.y][temp.x] = true;

		for (int i = 0; i < 4; i++) {
			int cy = temp.y + dy[i];
			int cx = temp.x + dx[i];
				
			if (cy == start.y && cx == start.x && temp.cnt >= 3)
				return 1;

			if (!is_in_range(cy, cx) || visited[cy][cx] || graph[cy][cx] != color)
				continue;

			stack.push({ cy,cx, temp.cnt + 1 });
		}
	}
	return 0;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> graph[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));

			int res = dfs({ i,j,0 });

			if (res) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}