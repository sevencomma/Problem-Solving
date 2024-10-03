#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M, P;
vector<int> sp;
vector<vector<point>> p_list;
vector<int> res(10);

char board[1000][1000];
bool visited[1000][1000];
bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

bool bfs(int who) {
	queue<point> q;
	for (auto& it : p_list[who]) {
		q.push(it);
		visited[it.y][it.x] = true;
	}
	p_list[who].clear();
	bool ing = false;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.cnt == sp[who])
			break;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx] == '.') {
				ing = true;
				q.push({ cy, cx, cur.cnt + 1 });
				visited[cy][cx] = true;
				p_list[who].push_back({ cy, cx });
				board[cy][cx] = who - 0 + '0';
			}
		}
	}
	return ing;
}

bool one_turn() {
	bool change = false;
	for (int i = 1; i <= P; i++) {
		res[i] += p_list[i].size();
		if (bfs(i))
			change = true;
	}
	return change;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> P;
	sp.resize(P + 1);
	p_list.resize(P + 1);
	for (int i = 1; i <= P; i++)
		cin >> sp[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] >= '1' && board[i][j] <= '9')
				p_list[board[i][j] - '0'].push_back({ i, j, 0 });
		}

	while (1) {
		if (!one_turn())
			break;
	}
	for (int i = 1; i <= P; i++)
		cout << res[i] << ' ';
}