#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N, M;
char board[20][20];
bool visited[20][20][20][20];

struct dat {
	int y1, x1, y2, x2, cnt;
};

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(vector<pair<int, int>> coins) {
	queue<dat> q;
	q.push({ coins[0].first, coins[0].second, coins[1].first, coins[1].second, 0 });
	visited[coins[0].first][coins[0].second][coins[1].first][coins[1].second] = true;

	while (!q.empty()) {
		dat cur = q.front();
		q.pop();

		if (cur.cnt == 10)
			continue;

		for (int i = 0; i < 4; i++) {
			int ny1 = cur.y1 + dy[i];
			int nx1 = cur.x1 + dx[i];

			int ny2 = cur.y2 + dy[i];
			int nx2 = cur.x2 + dx[i];

			if (is_in_range(ny1, nx1) != is_in_range(ny2, nx2))
				return cur.cnt + 1;

			if (is_in_range(ny1, nx1) && is_in_range(ny2, nx2)) {
				if (board[ny1][nx1] == '#') {
					ny1 = cur.y1;
					nx1 = cur.x1;
				}

				if (board[ny2][nx2] == '#') {
					ny2 = cur.y2;
					nx2 = cur.x2;
				}

				q.push({ ny1, nx1, ny2, nx2, cur.cnt + 1 });
				visited[ny1][nx1][ny2][nx2] = true;
			}
		}
	}

	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	vector<pair<int, int>> coins;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o')
				coins.push_back({ i, j });
		}
	cout << bfs(coins);
}