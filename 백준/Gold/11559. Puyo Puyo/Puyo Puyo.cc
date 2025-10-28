#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

char board[12][6];
bool visited[12][6];

bool is_in_range(int y, int x) {
	return (0 <= y && y < 12 && 0 <= x && x < 6);
}

void gravity() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == '.') continue;
			int ny = i + 1;
			while (ny < 11 && board[ny][j] == '.') ny++;
			if (board[ny][j] == '.') {
				board[ny][j] = board[i][j];
				board[i][j] = '.';
			}
			else if (ny - 1 != i) {
				board[ny - 1][j] = board[i][j];
				board[i][j] = '.';
			}
		}
	}
}

vector<pair<int, int>> bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	vector<pair<int, int>> res;
	res.push_back({ y, x });

	int cy, cx;
	while (!q.empty()) {
		tie(cy, cx) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (is_in_range(ny, nx) && !visited[ny][nx] && board[ny][nx] == board[y][x]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
				res.push_back({ ny, nx });
			}
		}
	}

	return res;
}

bool dontBomb() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == '.') continue;
			memset(visited, false, sizeof(visited));
			if (bfs(i, j).size() >= 4) return false;
		}
	return true;
}

void bomb() {
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == '.') continue;
			if (visited[i][j]) continue;

			vector<pair<int, int>> v = bfs(i, j);
			if (v.size() >= 4)
				for (auto& p : v)
					board[p.first][p.second] = '.';
		}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> board[i][j];
	int cnt = 0;
	while (1) {
		gravity();
		if (dontBomb()) break;
		bomb();
		cnt++;
	}
	cout << cnt;
}