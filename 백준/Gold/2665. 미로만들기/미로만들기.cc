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

int N;
char board[50][50];
bool visited[50][50];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

int bfs() {
	priority_queue<point, vector<point>, cmp> pq;
	pq.push({ 0, 0, 0 });
	visited[0][0] = true;

	while (!pq.empty()) {
		point cur = pq.top();
		pq.pop();

		if (cur.y == N - 1 && cur.x == N - 1)
			return cur.cnt;
		
		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx]) {
				if (board[cy][cx] == '1')
					pq.push({ cy, cx, cur.cnt });
				else
					pq.push({ cy, cx, cur.cnt + 1 });
				visited[cy][cx] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	cout << bfs();
}