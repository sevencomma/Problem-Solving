#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int y, x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N, M, x, y, a, b;
bool board[100][100];
bool visited[100][100];
bool can_move[100][100];
unordered_map<int, vector<point>> lamp_switch;

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

vector<point> edge;

int bfs() {
	board[0][0] = true;
	int res = 1;
	queue<point> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	can_move[0][0] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (auto& it : lamp_switch[cur.y * 100 + cur.x]) {
			if (!board[it.y][it.x]) {
				res++;
				board[it.y][it.x] = true;
			}
			bool go_ = false;
			if (!can_move[it.y][it.x]) {
				for (int i = 0; i < 4; i++) {
					int cy = it.y + dy[i];
					int cx = it.x + dx[i];

					if (is_in_range(cy, cx) && can_move[cy][cx]) {
						go_ = true;
					}
				}
				if (go_) {
					q.push({ it.y, it.x });
					visited[it.y][it.x] = true;
					can_move[it.y][it.x] = true;
				}
			}
		}
		lamp_switch[cur.y * 100 + cur.x].clear();

		bool move = false;
		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx]) {
				move = true;
				q.push({ cy, cx });
				visited[cy][cx] = true;
				can_move[cy][cx] = true;
			}
		}
		if (!move)
			edge.push_back({ cur.y, cur.x });
	}
	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		lamp_switch[(y - 1) * 100 + x - 1].push_back({b - 1, a - 1});
	}
	cout << bfs();
}