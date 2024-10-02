#include <bits/stdc++.h>
using namespace std;

map<int, int> digonal1; // y + x
map<int, int> digonal2; // N - y - 1 + x

int N;
int board[10][10];
bool visited[10][10];

int res1, res2;

bool is_safe(int y, int x) {
	if (digonal1[y + x] == 0 && digonal2[N - y - 1 + x] == 0)
		return true;
	return false;
}

void back_tracking(int y, int cnt) {
	if (cnt > res1)
		res1 = cnt;
	int j;
	for (int i = y; i < N; i++) {
		if (i % 2 == 1)
			j = 1;
		else j = 0;
		for (j; j < N; j += 2) {
			if (board[i][j] == 1 && !visited[i][j]) {
				if (is_safe(i, j)) {
					visited[i][j] = true;
					digonal1[i + j]++;
					digonal2[N - i - 1 + j]++;
					back_tracking(i, cnt + 1);
					digonal1[i + j]--;
					digonal2[N - i - 1 + j]--;
					visited[i][j] = false;
				}
			}
		}
	}
}

void back_tracking2(int y, int cnt) {
	if (cnt > res2)
		res2 = cnt;
	int j;
	for (int i = y; i < N; i++) {
		if (i % 2 == 0)
			j = 1;
		else j = 0;
		for (j; j < N; j += 2) {
			if (board[i][j] == 1 && !visited[i][j]) {
				if (is_safe(i, j)) {
					digonal1[i + j]++;
					digonal2[N - i - 1 + j]++;
					back_tracking2(i, cnt + 1);
					digonal1[i + j]--;
					digonal2[N - i - 1 + j]--;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	back_tracking(0, 0);
	back_tracking2(0, 0);
	cout << res1 + res2;
}