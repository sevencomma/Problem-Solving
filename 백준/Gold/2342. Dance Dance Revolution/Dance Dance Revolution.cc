#include <bits/stdc++.h>
using namespace std;

int x, N;
int arr[100001];
int cost[5][5];
int cache[100001][5][5]; // [idx][left][right]

int dp(int idx, int l, int r) {
	if (idx == N) return 0;
	int& ret = cache[idx][l][r];
	if (ret != -1) return ret;

	int nextPos = arr[idx];
	ret = min(dp(idx + 1, nextPos, r) + cost[l][nextPos], dp(idx + 1, l, nextPos) + cost[r][nextPos]);
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	while (1) {
		cin >> x;
		if (x == 0) break;
		arr[N++] = x;
	}

	for (int i = 1; i <= 4; i++)
		cost[0][i] = 2;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++) {
			if (i == j) cost[i][j] = 1;
			else cost[i][j] = (i % 2 == j % 2) ? 4 : 3;
		}

	cout << dp(0, 0, 0);
}