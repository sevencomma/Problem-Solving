#include <bits/stdc++.h>
using namespace std;

int N, L, J;
int Minus[20];
int Plus[20];

int cache[20][101];

int dp(int idx, int l) {
	if (l <= 0) return INT_MIN;
	if (idx == N) return 0;
	int& ret = cache[idx][l];
	if (ret != -1) return ret;
	
	ret = max(dp(idx + 1, l), dp(idx + 1, l - Minus[idx]) + Plus[idx]);
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Minus[i];
	for (int i = 0; i < N; i++) cin >> Plus[i];

	cout << dp(0, 100);
}