#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[50][50];
char target[50][50];

void turn(int y, int x) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			board[i + y][j + x] = (board[i + y][j + x] == '1') ? '0' : '1';
		}
}

bool isSame() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] != target[i][j])
				return false;
	return true;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> target[i][j];

	int cnt = 0;
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 3; j++) {
			if (board[i][j] != target[i][j]) {
				turn(i, j);
				cnt++;
			}
		}
	
	if (isSame())
		cout << cnt;
	else
		cout << -1;
}