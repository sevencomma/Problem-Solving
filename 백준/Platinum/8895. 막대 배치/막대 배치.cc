#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T, N, L, R;
ll cache[101][101][101];

ll dp(int n, int l, int r) {
	if (n == 0 || l < 0 || r < 0) return 0;
	if (n == 1 && l == 1 && r == 1) return 1;
	ll& ret = cache[n][l][r];
	if (ret != -1) return ret;
	return ret = dp(n - 1, l - 1, r) + dp(n - 1, l, r - 1) + dp(n - 1, l, r) * (n - 2);
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	memset(cache, -1, sizeof(cache));
	while (T--) {
		cin >> N >> L >> R;
		cout << dp(N, L, R) << '\n';
	}
}