#include <bits/stdc++.h>
using namespace std;

int N, K, b;
vector<int> x;
int cache[31][40001];	// -1:미확인, 0: 불가능, 1: 가능
// [i][j] : i ~ N - 1까지를 사용하여 j를 만들수 있는지 여부

int dp(int idx, int weight, int target) {
	if (weight == target) return 1;
	if (idx == N) return 0;
	int& ret = cache[idx][abs(target - weight)];

	if (ret != -1) return ret;
	ret = 0;

	return ret = (dp(idx + 1, weight, target) |
		dp(idx + 1, weight + x[idx], target) |
		dp(idx + 1, weight, target + x[idx]));
}

int main(void) {
	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++)
		cin >> x[i];
	cin >> K;
	memset(cache, -1, sizeof(cache));

	for (int j = 0; j < K; j++) {
		cin >> b;
		if (dp(0, 0, b) == 1) cout << "Y";
		else cout << "N";
		if (j < K - 1) cout << " ";
	}
}