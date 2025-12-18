#include <bits/stdc++.h>
using namespace std;

int N, M, v, w;
int value[301][20];
int cache[301][20];
int choice[301][20];

int dp(int money, int idx) {
	if (money < 0) return INT_MIN;
	if (money == 0 || idx == M) return 0;

	int& ret = cache[money][idx];
	if (ret != -1) return ret;

	for (int i = 0; i <= money; i++) {
		int vs = dp(money - i, idx + 1) + value[i][idx];
		if (ret < vs) {
			ret = vs;
			choice[money][idx] = i;
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> v;
		for (int j = 0; j < M; j++) {
			cin >> w;
			value[v][j] = w;
		}
	}

	int res = dp(N, 0);
	vector<int> resCnt(M);
	int cur = N;
	for (int i = 0; i < M; i++) {
		resCnt[i] = choice[cur][i];
		cur -= choice[cur][i];
	}

	cout << res << '\n';
	for (int i = 0; i < M; i++)
		cout << resCnt[i] << ' ';
}