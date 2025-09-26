#include <bits/stdc++.h>
using namespace std;

int N;
int player[100000][4];
int cache[100000][16][11];

// mask : 0 0 0 0 (bit) 각 A, B, C, D포지션에 한명이상 존재하는지
// 
// cnt명 선발, idx번째에, mask상황에서 얻을 수 있는 최대가중치
int dp(int idx, int mask, int cnt) {
	if (cnt == 11) {
		if (mask == 15) return 0;
		else return INT_MIN;
	}
	if (idx == N) return INT_MIN;
	int& ret = cache[idx][mask][cnt];
	if (ret != -1) return ret;
	ret = dp(idx + 1, mask, cnt);

	for (int i = 0; i < 4; i++) {
		int newMask = mask | (1 << i);
		ret = max(ret, dp(idx + 1, newMask, cnt + 1) + player[idx][i]);
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			cin >> player[i][j];
	cout << dp(0, 0, 0);
}