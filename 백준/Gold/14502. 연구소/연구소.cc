#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M;
int board[10][10];
int board_temp[10][10];
bool visited[10][10];
bool isused[10][10];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

void bfs();
int find_safety();
vector<point> virus;
int res;
void back_tracking(int cnt) {
	if (cnt == 3) {
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				board_temp[i][j] = board[i][j];
		bfs();
		res = max(res, find_safety());
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!isused[i][j] && board[i][j] == 0) {
				board[i][j] = 1;
				isused[i][j] = true;
				back_tracking(cnt + 1);
				isused[i][j] = false;
				board[i][j] = 0;
			}
		}
	}
}

void bfs() {
	queue<point> q;
	for (auto& it : virus) {
		q.push({ it.y, it.x });
		visited[it.y][it.x] = true;
	}
	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board_temp[cy][cx] == 0) {
				q.push({ cy, cx });
				visited[cy][cx] = true;
				board_temp[cy][cx] = 2;
			}
		}
	}
}

int find_safety() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board_temp[i][j] == 0)
				cnt++;
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] == 2)
				virus.push_back({ i, j });
	back_tracking(0);
	cout << res;
}