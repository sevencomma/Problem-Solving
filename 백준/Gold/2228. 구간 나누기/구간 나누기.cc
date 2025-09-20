#include <bits/stdc++.h>
using namespace std;

#define M_INF -123456789

int N, M;
int arr[100];
int prefixSum[100];
int cache[50][100][100]; 
// [k][l][r];
// k번째 구간 선택, [l, r]은 허용범위

int subSum(int l, int r) {
	if (l == 0)
		return prefixSum[r];
	return prefixSum[r] - prefixSum[l - 1];
}

int dp(int k, int l, int r) {
	if (k == M) return 0;
	if (l > r) return M_INF;

	int& ret = cache[k][l][r];
	if (ret != -1) return ret;
	ret = M_INF;

	for (int i = l; i <= r; i++)
		for (int j = i; j <= r; j++) {
			// [i][j] 선택
			// 구간 선택은 앞에서 부터 선택함.

			ret = max(ret, dp(k + 1, j + 2, r) + subSum(i, j));
		}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	prefixSum[0] = arr[0];
	for (int i = 1; i < N; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	
	cout << dp(0, 0, N - 1);
}