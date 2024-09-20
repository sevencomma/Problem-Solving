#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

char board[5][5];
bool visited[5][5];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N = 5;

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

void bfs(vector<int>& List);
vector<int> list_(7);
bool isused[25];
void make_list(int index, int cnt) {
	if (cnt == 7) {
		bfs(list_);
		return;
	}

	for (int i = index; i < 25; i++) {
		if (!isused[i]) {
			list_[cnt] = i;
			isused[i] = true;
			make_list(i + 1, cnt + 1);
			isused[i] = false;
		}
	}
}

int res;

void bfs(vector<int>& List) {
	int count = 0;
	memset(visited, false, sizeof(visited));
	int temp[5][5] = { 0, };
	for (int i = 0; i < List.size(); i++) {
		int Y = List[i] / 5;
		int X = List[i] % 5;
		temp[Y][X] = 1;
	}
	
	queue<point> q;
	q.push({ List[0] / 5, List[0] % 5});
	visited[List[0] / 5][List[0] % 5] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		count++;
		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (is_in_range(cy, cx) && !visited[cy][cx] && temp[cy][cx]) {
				q.push({ cy, cx });
				visited[cy][cx] = true;
			}
		}
	}
	if (count == 7) {
		int dasom = 0;
		for (int i = 0; i < List.size(); i++) {
			int Y = List[i] / 5;
			int X = List[i] % 5;
			if (board[Y][X] == 'S')
				dasom++;
		}
		if (dasom >= 4)
			res++;
	}
}

int main(void) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	make_list(0, 0);
	cout << res;
}