#include <bits/stdc++.h>
using namespace std;

int T, W;
int pos[1001];
int cache[1001][31][3];

int dp(int t, int w, int p) {
	if (t == T) return 0;
	int& ret = cache[t][w][p];
	if (ret != -1) return ret;

	ret = 0;
	int newW;
	for (int next : {1, 2}) {
		newW = (next == p) ? w : w + 1;
		if (w == W && next != p) continue;

		if (pos[t + 1] == next)
			ret = max(ret, dp(t + 1, newW, next) + 1);
		else
			ret = max(ret, dp(t + 1, newW, next));
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
		cin >> pos[i];

	cout << dp(0, 0, 1);
}