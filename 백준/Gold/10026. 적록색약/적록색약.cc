#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};
int N;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char board[100][100];
bool visited[100][100];

bool is_in_range(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < N);
}

int bfs(int y, int x) {
	if (visited[y][x])
		return 0;
	queue<point> q;
	visited[y][x] = true;
	q.push({ y,x });
	int color = board[y][x];

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (!is_in_range(cy, cx) || visited[cy][cx] || board[cy][cx] != color)
				continue;

			visited[cy][cx] = true;
			q.push({ cy,cx });
		}
	}
	return 1;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int a = 0, b = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a += bfs(i, j);

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == 'R')
				board[i][j] = 'G';

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			b += bfs(i, j);
	cout << a << " " << b;
}