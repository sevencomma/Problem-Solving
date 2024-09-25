#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int y, x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N, L, R;
int board[51][51];
bool visited[51][51];
int board_identify[51][51];
int color;

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

void bfs(int y, int x) {
	if (visited[y][x])
		return;
	color++;
	queue<point> q;
	q.push({ y, x });
	visited[y][x] = true;
	int check = 0;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx]) {
				int d = abs(board[cur.y][cur.x] - board[cy][cx]);
				if (d >= L && d <= R) {
					check++;
					q.push({ cy, cx });
					visited[cy][cx] = true;
					board_identify[cy][cx] = color;
				}
			}
		}
	}
	if (check > 0)
		board_identify[y][x] = color;
}

void move_people() {
	unordered_map<int, vector<point>> kind_of;
	vector<int> sum(color + 1, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board_identify[i][j] > 0) {
				kind_of[board_identify[i][j]].push_back({ i, j });
				sum[board_identify[i][j]] += board[i][j];
			}
	for (auto& it1 : kind_of) {
		int count = it1.second.size();
		int alloc = sum[it1.first] / count;
		for (auto& it2 : it1.second)
			board[it2.y][it2.x] = alloc;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	int day = 0;
	while (1) {
		memset(visited, false, sizeof(visited));
		memset(board_identify, 0, sizeof(board_identify));
		color = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				bfs(i, j);
	
		bool go_move = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (board_identify[i][j])
					go_move = true;
		if (go_move)
			move_people();
		else
			break;
		day++;
	}
	cout << day;
}