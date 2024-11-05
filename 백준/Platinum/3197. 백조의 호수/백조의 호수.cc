#include <bits/stdc++.h>
using namespace std;

#define CHANGE(y, x) ((y)*1500 + (x))

struct point {
	int y, x;
	bool one_;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int R, C;

char board[1500][1500];
bool visited[1500][1500];

int parent[2300000];
int Rank[2300000];

void Link(int x, int y) {
	if (Rank[x] > Rank[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y] = Rank[x] + 1;
	}
}
int Find(int x) {
	if (parent[x] != x) {
		parent[x] = Find(parent[x]);
	} return parent[x];
}
void Union(int x, int y) {
	Link(Find(x), Find(y));
}

bool is_in_range(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

void bfs(vector<pair<int, int>>& list) {
	queue<point> q;
	for (auto& it : list) {
		q.push({ it.first, it.second, false });
		visited[it.first][it.second] = true;
	}
	list.clear();

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];
			
			if (is_in_range(cy, cx) && !visited[cy][cx]) {
				if (board[cy][cx] == 'X' && cur.one_ == false) {
					list.push_back({ cy, cx });
					q.push({ cy, cx, true });
					board[cy][cx] = '.';
				}
				else if (board[cy][cx] == 'X')
					continue;
				else 
					q.push({ cy, cx, cur.one_ });
				visited[cy][cx] = true;
				if (Find(CHANGE(cur.y, cur.x)) != Find(CHANGE(cy, cx)))
					Union(CHANGE(cur.y, cur.x), CHANGE(cy, cx));
			}
		}
	}
}



int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	vector<pair<int, int>> W;
	vector<pair<int, int>> L;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L')
				L.push_back({ i, j });
			if (board[i][j] != 'X')
				W.push_back({ i, j });
		}
	for (int i = 0; i < CHANGE(R, C) + 1; i++)
		parent[i] = i;

	queue<point> q;
	for (auto& it : L) {
		q.push({ it.first, it.second });
		visited[it.first][it.second] = true;
	}
	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && board[cy][cx] != 'X') {
				q.push({ cy, cx });
				visited[cy][cx] = true;
				if (Find(CHANGE(cur.y, cur.x)) != Find(CHANGE(cy, cx)))
					Union(CHANGE(cur.y, cur.x), CHANGE(cy, cx));
			}
		}
	} int cnt = 0;
	while (Find(CHANGE(L[0].first, L[0].second)) != Find(CHANGE(L[1].first, L[1].second)) || W.size() == 0) {
		bfs(W);
		for (auto& it : W) {
			for (int i = 0; i < 4; i++) {
				int cy = it.first + dy[i];
				int cx = it.second + dx[i];

				if (is_in_range(cy, cx) && board[cy][cx] != 'X') {
					if (Find(CHANGE(it.first, it.second)) != Find(CHANGE(cy, cx)))
						Union(CHANGE(it.first, it.second), CHANGE(cy, cx));
				}
			}
		}
		cnt++;
	} cout << cnt;
}