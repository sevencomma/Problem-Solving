#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 123456789

int N, M, a, b, c;
int cost[2501];
vector<pair<int, int>> graph[2501];
ll cache[2501][2501];
// idx, 지금까지 만난 최소cost : 총 최소 금액

ll dijkstra(int start) {
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
	pq.push({ 0, start, cost[start] });
	cache[start][cost[start]] = 0;

	while (!pq.empty()) {
		ll dist;
		int cur, minCost;
		tie(dist, cur, minCost) = pq.top();
		pq.pop();

		if (cur == N)
			return dist;
		if (cache[cur][minCost] < dist)
			continue;

		int next, d;
		for (auto& it : graph[cur]) {
			tie(next, d) = it;
			int newMinCost = min(minCost, cost[next]);
			ll newDist = dist + (ll)d * (ll)minCost;
			if (cache[next][newMinCost] == -1 || cache[next][newMinCost] > newDist) {
				cache[next][newMinCost] = newDist;
				pq.push({ newDist, next, newMinCost });
			}
		}
	}
	return -1;
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

	cout << dijkstra(1);
}