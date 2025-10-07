#include <bits/stdc++.h>
using namespace std;

int N;
int score[1000];
int minSub[1000][1000];
int maxSub[1000][1000];
int cache[1000];

int dp(int idx) {
	if (idx == N)
		return 0;
	int& ret = cache[idx];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = idx; i < N; i++) {
		ret = max(ret, dp(i + 1) + (maxSub[idx][i] - minSub[idx][i]));
	}
	return ret;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> score[i];

	for (int i = 0; i < N; i++) {
		int mn = score[i], mx = score[i];
		for (int j = i; j < N; j++) {
			mn = min(mn, score[j]);
			mx = max(mx, score[j]);
			minSub[i][j] = mn;
			maxSub[i][j] = mx;
		}
	}

	cout << dp(0);
}