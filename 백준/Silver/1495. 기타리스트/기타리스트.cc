#include <bits/stdc++.h>
using namespace std;

int N, S, M;
int arr[50];
int cache[50][1001];

int dp(int idx, int volume) {
	if (idx == N) return volume;
	int& ret = cache[idx][volume];
	if (ret != -2) return ret;
	ret = -1;

	if (volume - arr[idx] >= 0)
		ret = max(ret, dp(idx + 1, volume - arr[idx]));
	if (volume + arr[idx] <= M)
		ret = max(ret, dp(idx + 1, volume + arr[idx]));

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= M; j++)
			cache[i][j] = -2;

	cout << dp(0, S);
}