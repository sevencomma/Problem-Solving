#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;

	bool operator < (const point& p) const {
		if (y == p.y)
			return x > p.x;
		return y > p.y;
	}
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int H, W;
char board[102][102];
int visited[102][102];
bool key[26];
set<point> dollar;

bool is_in_range(int y, int x) {
	return y >= 0 && y < H + 2 && x >= 0 && x < W + 2;
}

void bfs() {
	queue<point> q;
	q.push({ 0,0 });
	visited[0][0]++;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (board[cur.y][cur.x] == '$')
			dollar.insert({ cur.y, cur.x });

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && board[cy][cx] != '*' && !visited[cy][cx]) {
				if (board[cy][cx] >= 'a' && board[cy][cx] <= 'z' && !key[board[cy][cx] - 'a']) {
					key[board[cy][cx] - 'a'] = true;
					memset(visited, false, sizeof(visited));
				}
				if (board[cy][cx] >= 'A' && board[cy][cx] <= 'Z') {
					if (key[board[cy][cx] - 'A']) {
						q.push({ cy, cx });
						visited[cy][cx]++;
					}
				}
				else {
					q.push({ cy,cx });
					visited[cy][cx]++;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> H >> W;
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
		memset(key, false, sizeof(key));
		dollar.clear();

		for (int row = 1; row < H + 1; row++)
			for (int col = 1; col < W + 1; col++)
				cin >> board[row][col];
		cin.ignore();
		string sequence;
		getline(cin, sequence);
		if (sequence != "0")
			for (auto k : sequence)
				key[k - 'a'] = true;
		bfs();
		cout << dollar.size() << "\n";
	}
}