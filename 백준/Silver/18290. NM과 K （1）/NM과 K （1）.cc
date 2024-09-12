#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[10][10];
int visited[10][10]; // 1 : check, 0 : available, -1 : can't
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int res = INT_MIN;

bool is_in_range(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}

void back_tracking(int y, int x, int count, int sum) {
	if (count == K) {
		if (sum > res)
			res = sum;
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				int temp[4];
				for (int a = 0; a < 4; a++) {
					int cy = i + dy[a];
					int cx = j + dx[a];
					if (is_in_range(cy, cx)) {
						temp[a] = visited[cy][cx];
						visited[cy][cx] = -1;
					}
				}
				visited[i][j] = 1;
				back_tracking(i, j, count + 1, sum + board[i][j]);
				for (int a = 0; a < 4; a++) {
					int cy = i + dy[a];
					int cx = j + dx[a];
					if (is_in_range(cy, cx))
						visited[cy][cx] = temp[a];
				}
				visited[i][j] = 0;
			}
		}
	}

}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	back_tracking(0, 0, 0, 0);
	cout << res;
}