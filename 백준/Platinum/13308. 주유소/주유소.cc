#include <bits/stdc++.h>
using namespace std;

#define INF 123456789

int N, M, a, b, c;
int cost[2501];
vector<pair<int, int>> graph[2501];
int cache[2501][2501];
// idx, 지금까지 만난 최소cost : 총 최소 금액

int dp(int cur, int minCost) {
	if (cur == N) return 0;
	int& ret = cache[cur][minCost];
	if (ret != -1) return ret;
	ret = INF;

	int next, d;
	for (auto& it : graph[cur]) {
		tie(next, d) = it;
		ret = min(ret, dp(next, min(minCost, cost[next])) + d * minCost);
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> cost[i];

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	cout << dp(1, cost[1]);
}