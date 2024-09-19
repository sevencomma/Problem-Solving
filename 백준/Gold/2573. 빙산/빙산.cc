#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

int n, m;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool is_in_range(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < m);
}

int board[300][300];

bool is_melted() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 0)
				return false;
	return true;
}

void one_time() {
	int temp[300][300] = { 0, };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int cy = i + dy[k];
					int cx = j + dx[k];
					if (is_in_range(cy, cx) && board[cy][cx] == 0)
						cnt++;
				}
				temp[i][j] += cnt;
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			board[i][j] -= temp[i][j];
			if (board[i][j] < 0)
				board[i][j] = 0;
		}
}

bool visited[300][300];

void bfs(int y, int x) {
	queue<point> q;
	q.push({ y, x });
	visited[y][x] = true;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];
				
			if (is_in_range(cy, cx) && board[cy][cx] && !visited[cy][cx]) {
				q.push({ cy, cx });
				visited[cy][cx] = true;
			}
		}
	}
}

bool is_seperate() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 0) {
				bfs(i, j);
				goto jump;
			}
	jump:
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 0 && visited[i][j] != true)
				return true;
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int count = 0;
	bool res = false;
	while (!is_melted()) {
		if (is_seperate()) {
			res = true;
			break;
		}
		one_time();
		count++;
	}
	if (!res)
		count = 0;
	cout << count;
}