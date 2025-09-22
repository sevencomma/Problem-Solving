#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
bool board[32][32];
ll cache[32][32][3]; // 오, 아, 오아

ll func(int y, int x, int mode) {
	if (y < 0 || x < 0 || board[y][x]) return 0;
	ll& ret = cache[y][x][mode];
	if (ret != -1) return ret;
	ret = 0;

	if (mode == 0) {
		if (!board[y][x - 1])
			for (int i : {0, 2})
				ret += func(y, x - 1, i);
	}
	else if (mode == 1) {
		if (!board[y - 1][x])
			for (int i : {1, 2})
				ret += func(y - 1, x, i);
	}
	else {
		if (!board[y - 1][x] && !board[y - 1][x - 1] && !board[y][x - 1])
			for (int i : {0, 1, 2})
				ret += func(y - 1, x - 1, i);
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	memset(cache, -1, sizeof(cache));
	cache[0][1][0] = 1;
	ll sum = 0;
	for (int i = 0; i < 3; i++)
		sum += func(N - 1, N - 1, i);
	cout << sum;
}