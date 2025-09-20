#include <bits/stdc++.h>
using namespace std;

int T, K, p, n;
int P[100];
int N[100];
int cache[10000][100];

int dp(int money, int k) {
	if (money == T) return 1;
	if (money > T) return 0;
	if (k == K) return 0;

	int& ret = cache[money][k];
	if (ret != -1) return ret;
	ret = 0;
	
	for (int i = 0; i <= N[k]; i++) {
		int cost = i * P[k];
		ret += dp(money + cost, k + 1);
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T >> K;
	for (int i = 0; i < K; i++)
		cin >> P[i] >> N[i];

	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0);
}