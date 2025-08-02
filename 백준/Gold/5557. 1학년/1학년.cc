#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int arr[101];
ll cache[101][30];

ll dp(int idx, int num) {
	if (num < 0) return 0;
	if (idx == N - 2)
		return (num == arr[N - 1]) ? 1 : 0;
	if (num > 20) return 0;
	ll& ret = cache[idx][num];
	if (ret != -1) return ret;
	return ret = dp(idx + 1, num + arr[idx + 1]) + dp(idx + 1, num - arr[idx + 1]);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	memset(cache, -1, sizeof(cache));
	cout << dp(0, arr[0]);
}