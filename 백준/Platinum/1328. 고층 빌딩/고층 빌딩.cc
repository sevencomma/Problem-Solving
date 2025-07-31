#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int N, L, R;
int cache[101][101][101];

int dp(int n, int l, int r) {
	if (n == 0 || l < 0 || r < 0) return 0;
	if (n == 1 && l == 1 && r == 1) return 1;
	int& ret = cache[n][l][r];
	if (ret != -1) return ret;

	return ret = (dp(n - 1, l - 1, r) + dp(n - 1, l, r - 1) + (ll)dp(n - 1, l, r) * (n - 2)) % MOD;
}

int main(void) {
	cin >> N >> L >> R;
	memset(cache, -1, sizeof(cache));
	cout << dp(N, L, R);
}