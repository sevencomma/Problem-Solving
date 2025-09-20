#include <bits/stdc++.h>
using namespace std;

int T, N;
int cards[1000];
int cache[1000][1000];	// [l][j] 상황에서 근우가 얻을 수 있는 최대점수

// turn % 2 == 0: 근우
// else : 명우
int dp(int l, int r, int turn) {
	if (l > r) return 0;

	int& ret = cache[l][r];
	if (ret != -1) return ret;

	if (turn % 2 == 0)
		ret = max(dp(l + 1, r, turn + 1) + cards[l], dp(l, r - 1, turn + 1) + cards[r]);
	else
		ret = min(dp(l + 1, r, turn + 1), dp(l, r - 1, turn + 1));
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(cards, 0, sizeof(cards));
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> cards[i];
		cout << dp(0, N - 1, 0) << '\n';
	}
}