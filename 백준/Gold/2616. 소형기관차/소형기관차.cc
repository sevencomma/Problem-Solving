#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[50001];
int prefixSum[50001];
int cache[3][50001];

int partSum(int l, int r) {
	return prefixSum[r] - prefixSum[l - 1];
}

int dp(int cnt, int idx) {
	if (cnt == 3) return 0;
	if (idx + M - 1 > N) return INT_MIN;
	int& ret = cache[cnt][idx];
	if (ret != -1) return ret;

	ret = max(dp(cnt, idx + 1), dp(cnt + 1, idx + M) + partSum(idx, idx + M - 1));
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> M;
	for (int i = 1; i <= N; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];

	cout << dp(0, 1);
}