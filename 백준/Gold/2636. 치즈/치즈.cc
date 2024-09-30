#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

struct cmp {
	bool operator() (point a, point b) const {
		return a.cnt > b.cnt;
	}
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M;
int board[100][100];
int board_time[100][100];
vector<point> edge;
bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void bfs() {
	priority_queue<point, vector<point>, cmp> q;
	for (auto& it : edge) {
		q.push({ it.y, it.x, it.cnt });
	}
	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		if (board[cur.y][cur.x] == 0)
			board_time[cur.y][cur.x] = 0;
		else
			board_time[cur.y][cur.x] = min(board_time[cur.y][cur.x], cur.cnt);

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && board_time[cy][cx] > cur.cnt) {
				if (board[cy][cx] == 1) {
					q.push({ cy, cx, cur.cnt + 1 });
				}
				else
					q.push({ cy, cx, cur.cnt });
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		if (!board[i][0])
			edge.push_back({ i, 0 });
		else
			edge.push_back({ i, 0, 1 });
		if (!board[i][M - 1])
			edge.push_back({ i, M - 1 });
		else
			edge.push_back({ i, M - 1, 1 });
	}
	for (int j = 1; j < M - 1; j++) {
		if (!board[0][j])
			edge.push_back({ 0, j });
		else
			edge.push_back({ 0, j, 1 });
		if (!board[N - 1][j])
			edge.push_back({ N - 1, j });
		else
			edge.push_back({ N - 1, j, 1 });
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board_time[i][j] = INT_MAX;
	bfs();
	int res = 0, count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			res = max(res, board_time[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board_time[i][j] == res)
				count++;
	cout << res << "\n" << count;
}