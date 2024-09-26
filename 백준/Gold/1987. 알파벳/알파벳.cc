#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int y, x;
};

int R, C;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char board[20][20];
bool alphabet[27];

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

int res;
void dfs(int y, int x, int count) {
	if (count > res)
		res = count;

	for (int i = 0; i < 4; i++) {
		int cy = y + dy[i];
		int cx = x + dx[i];

		if (is_in_range(cy, cx) && !alphabet[board[cy][cx] - 'A']) {
			alphabet[board[cy][cx] - 'A'] = true;
			dfs(cy, cx, count + 1);
			alphabet[board[cy][cx] - 'A'] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	alphabet[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << res;
}