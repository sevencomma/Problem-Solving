#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt, dir;
	bool sw1, sw2;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M;
vector<pair<int, int>> target;
char board[50][50];
bool visited[50][50][4][2][2];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(int y, int x) {
	queue<point> q;
	q.push({ y, x, 0, -1, false, false });

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.sw1 && cur.sw2)
			return cur.cnt;

		for (int i = 0; i < 4; i++) {
			if (i == cur.dir)
				continue;
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx][i][cur.sw1][cur.sw2] && board[cy][cx] != '#') {
				bool tsw1 = cur.sw1, tsw2 = cur.sw2;
				if (cy == target[0].first && cx == target[0].second)
					tsw1 = true;
				if (cy == target[1].first && cx == target[1].second)
					tsw2 = true;
				q.push({ cy, cx, cur.cnt + 1, i, tsw1, tsw2 });
				visited[cy][cx][i][tsw1][tsw2] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int sy, sx;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S')
				sy = i, sx = j;
			if (board[i][j] == 'C')
				target.push_back({ i, j });
		}
	cout << bfs(sy, sx);
}