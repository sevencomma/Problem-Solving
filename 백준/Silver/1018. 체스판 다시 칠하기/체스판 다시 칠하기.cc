#include <bits/stdc++.h>
using namespace std;

char board[50][50];
int N, M, ans = INT_MAX;

int check(int i, int j) {
	int cnt = 0;
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++) {
			if ((y + x) % 2 && board[i + y][j + x] == 'W')
				cnt++;
			if ((y + x) % 2 == 0 && board[i + y][j + x] == 'B')
				cnt++;
		}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N - 7; i++) 
		for (int j = 0; j < M - 7; j++) {
			int a, b;
			a = check(i, j);
			b = 64 - a;
			ans = min(ans, min(a, b));
		}
	cout << ans;
}