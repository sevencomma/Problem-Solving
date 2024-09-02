#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;

bool is_in_range(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < m);
}

bool visited[101][101] = { false };;
int graph[101][101] = { 0 };

int bfs(int y, int x) {
	queue<point> q;
	q.push({ y,x,1 });
	visited[y][x] = true;

	while (!q.empty()) {
		point temp = q.front();
		q.pop();

		if (temp.y == n-1 && temp.x == m-1)
			return temp.cnt;

		for (int i = 0; i < 4; i++) {
			int cy = temp.y + dy[i];
			int cx = temp.x + dx[i];

			if (!is_in_range(cy, cx) || graph[cy][cx] == 0 || visited[cy][cx])
				continue;

			q.push({ cy,cx, temp.cnt + 1 });
			visited[cy][cx] = true;
		}
	}
}

int main(void) 
{
	cin >> n >> m;
	cin.ignore();
	string sentence;

	for (int i = 0; i < n; i++) {
		getline(cin, sentence);
		for (int j = 0; j < m; j++) {
			graph[i][j] = sentence[j] - '0';
		}
	}

	cout << bfs(0, 0);
}