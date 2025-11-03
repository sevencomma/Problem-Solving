#include <bits/stdc++.h>
using namespace std;

#define INF 123456789

int T, N, W;
int enemy[2][10001];
int cache[10000][3];

int dp(int idx, int status) {
	if (idx < 0) return INF;
	if (idx == 0) {
		if (status == 0) {
			if (enemy[0][0] + enemy[1][0] <= W)
				return 1;
			else return 2;
		}
		return 1;
	}
	int& ret = cache[idx][status];
	if (ret != -1) return ret;

	ret = INF;
	
	if (status == 0) {
		ret = min(ret, dp(idx - 1, 0) + 2);

		if (enemy[0][idx] + enemy[1][idx] <= W)
			ret = min(ret, dp(idx - 1, 0) + 1);

		if (enemy[0][idx - 1] + enemy[0][idx] <= W)
			ret = min(ret, dp(idx - 1, 2) + 2);

		ret = min(ret, dp(idx - 1, 2) + 3);

		if (enemy[1][idx - 1] + enemy[1][idx] <= W)
			ret = min(ret, dp(idx - 1, 1) + 2);

		ret = min(ret, dp(idx - 1, 1) + 3);

		if (enemy[0][idx - 1] + enemy[0][idx] <= W &&
			enemy[1][idx - 1] + enemy[1][idx] <= W) {
			if (idx == 1) ret = min(ret, 2);
			else ret = min(ret, dp(idx - 2, 0) + 2);
		}
	}
	else if (status == 1) {
		ret = min(ret, dp(idx - 1, 0) + 1);

		if (enemy[0][idx - 1] + enemy[0][idx] <= W)
			ret = min(ret, dp(idx - 1, 2) + 1);

		ret = min(ret, dp(idx - 1, 2) + 2);
	}
	else if (status == 2) {
		ret = min(ret, dp(idx - 1, 0) + 1);

		if (enemy[1][idx - 1] + enemy[1][idx] <= W)
			ret = min(ret, dp(idx - 1, 1) + 1);

		ret = min(ret, dp(idx - 1, 1) + 2);
	}

	return ret;
}

int solve() {
	if (N == 1) {
		if (enemy[0][0] + enemy[1][0] <= W)
			return 1;
		return 2;
	}

	memset(cache, -1, sizeof(cache));

	map<pair<int, int>, int> saved;
	saved[{0, 0}] = enemy[0][0];
	saved[{1, 0}] = enemy[1][0];
	saved[{0, N - 1}] = enemy[0][N - 1];
	saved[{1, N - 1}] = enemy[1][N - 1];

	int res = INF;
	res = min(res, dp(N - 1, 0));

	if (enemy[0][0] + enemy[0][N - 1] <= W) {
		memset(cache, -1, sizeof(cache));
		enemy[0][0] = INF;
		enemy[0][N - 1] = INF;
		res = min(res, dp(N - 1, 0) - 1);
		enemy[0][0] = saved[{0, 0}];
		enemy[0][N - 1] = saved[{0, N - 1}];
	}

	if (enemy[1][0] + enemy[1][N - 1] <= W) {
		memset(cache, -1, sizeof(cache));
		enemy[1][0] = INF;
		enemy[1][N - 1] = INF;
		res = min(res, dp(N - 1, 0) - 1);
		enemy[1][0] = saved[{1, 0}];
		enemy[1][N - 1] = saved[{1, N - 1}];
	}

	if (enemy[0][0] + enemy[0][N - 1] <= W &&
		enemy[1][0] + enemy[1][N - 1] <= W) {
		memset(cache, -1, sizeof(cache));
		enemy[0][0] = INF;
		enemy[0][N - 1] = INF;
		enemy[1][0] = INF;
		enemy[1][N - 1] = INF;
		res = min(res, dp(N - 1, 0) - 2);
	}

	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> W;
		memset(enemy, 0, sizeof(enemy));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
				cin >> enemy[i][j];
		cout << solve() << '\n';
	}
}