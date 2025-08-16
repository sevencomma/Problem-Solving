#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1 };
int dx[4] = { 1, 1, 1 };

int R, C, res;
char board[10000][500];
bool visited[10000][500];

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

bool dfs(int y, int x) {
	if (x == C - 1) {
		res++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (is_in_range(ny, nx) && !visited[ny][nx] && board[ny][nx] != 'x') {
			visited[ny][nx] = true;
			if (dfs(ny, nx))
				return true;
		}
	}

	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];

	bool can = false;
	for (int i = 0; i < R; i++) 
		if (board[i][0] != 'x')
			dfs(i, 0);

	cout << res;
}