#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<int> arr;
int cache[20][100001];

int dp(int idx, int sum) {
	if (idx == N) {
		if (sum == M)
			return 1;
		return 0;
	}
	if (sum > M) return 0;

	int& ret = cache[idx][sum];
	if (ret != -1) return ret;
	ret = 0;

	int nums = 0;
	while (1) {
		int nextSum = sum + (arr[idx] * nums);
		if (nextSum > M) break;
		ret += dp(idx + 1, nextSum);
		nums++;
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		cin >> N;
		arr.resize(N);
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		cin >> M;
		sort(arr.begin(), arr.end());
		cout << dp(0, 0) << '\n';
		arr.clear();
	}
}