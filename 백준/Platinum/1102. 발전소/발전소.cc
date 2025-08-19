#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, P;
string input;
int cost[16][16];
int cache[16][1 << 16];

int dp(int yCnt, int mask) {
	if (yCnt >= P) return 0;
	int& ret = cache[yCnt][mask];
	if (ret != -1) return ret;
	ret = INF;
	bitset<16> bit = mask;

	for (int i = 0; i < N; i++)
		if (bit[i])
			for (int j = 0; j < N; j++)
				if (!bit[j])
					ret = min(ret, dp(yCnt + 1, mask | (1 << j)) + cost[i][j]);

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	cin >> input >> P;
	memset(cache, -1, sizeof(cache));
	
	int yCnt = 0, mask = 0;
	for (int i = 0; i < N; i++)
		if (input[i] == 'Y') {
			yCnt++;
			mask = mask | (1 << i);
		}
	int ret = dp(yCnt, mask);
	if (ret != INF) cout << ret;
	else cout << -1;
}