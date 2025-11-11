#include <bits/stdc++.h>
using namespace std;

#define NINF -987654321
int N;
int arr[50];
int cache[50][250001];

int dp(int idx, int diff) {
	if (diff > 250000) return NINF;

	if (idx == N) {
		if (diff == 0)
			return 0;
		else
			return NINF;
	}
	int& ret = cache[idx][diff];
	if (ret != -1) return ret;

	ret = NINF;
	ret = max(ret, dp(idx + 1, diff));
	ret = max(ret, dp(idx + 1, diff + arr[idx]));
	
	// idx번째 diff만큼 차이날때, 추가할 수 있는 공통영역을 더해줌.
	if (arr[idx] < diff)
		ret = max(ret, dp(idx + 1, diff - arr[idx]) + arr[idx]);
	else
		ret = max(ret, dp(idx + 1, arr[idx] - diff) + diff);

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int res = dp(0, 0);
	if (res <= 0)
		cout << -1;
	else
		cout << res;
}