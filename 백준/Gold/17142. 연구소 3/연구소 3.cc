#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int	N, M;

int board[51][51];
int temp_board[51][51];
bool visited[51][51];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

int res = INT_MAX;

int bfs(vector<point> virus_on) {
	queue<point> q;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 2)
				temp_board[i][j] = 2;
			else if (board[i][j] == 1)
				temp_board[i][j] = -1;
			else
				temp_board[i][j] = board[i][j];
		}
	for (int i = 0; i < virus_on.size(); i++) {
		q.push({ virus_on[i].y, virus_on[i].x, 0 });
		visited[virus_on[i].y][virus_on[i].x] = true;
	}
	int count = 0;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.cnt > count && temp_board[cur.y][cur.x] != 2)
			count = cur.cnt;

		if (temp_board[cur.y][cur.x] != 2)
			temp_board[cur.y][cur.x] = 1;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && temp_board[cy][cx] != -1) {
				q.push({ cy,cx,cur.cnt + 1 });
				visited[cy][cx] = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (temp_board[i][j] == 0)
				return INT_MAX;
	return count;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	vector<point> virus;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i, j });
		}
	vector<int> isused(virus.size(), 0);
	for (int i = 0; i < M; i++)
		isused[i] = 1;

	do {
		vector<point> virus_on;
		for (int i = 0; i < virus.size(); i++) {
			if (isused[i]) {
				virus_on.push_back({ virus[i].y, virus[i].x });
			}
		}
		res = min(res, bfs(virus_on));
	} while (prev_permutation(isused.begin(), isused.end()));
	if (res == INT_MAX)
		res = -1;
	cout << res;
}