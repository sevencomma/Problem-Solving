#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int C, N;
pair<int, int> arr[21];	// { cost, weight }
int cache[21][1001]; // [idx][남은 인원]

int dp(int idx, int target) {
	if (idx == N) return (target <= 0) ? 0 : INF;
	if (target <= 0) return 0;
	int& ret = cache[idx][target];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i <= 1000; i++) {
		int nextCost = arr[idx + 1].first * i;
		int nextWeight = arr[idx + 1].second * i;

		ret = min(ret, dp(idx + 1, max(0, target - nextWeight)) + nextCost);
		if (target - nextWeight <= 0)
			break;
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> C >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i].first >> arr[i].second;
	cout << dp(0, C);
}