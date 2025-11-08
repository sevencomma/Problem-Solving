#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, w;
vector<pair<int, int>> adj[1001];

int solve(int s, int t) {
	if (s == t) return 0;
	vector<int> dist(N + 1, -1);
	queue<pair<int, int>> q;
	q.push({ s, 0 });
	dist[s] = 0;

	while (!q.empty()) {
		auto [u, w] = q.front();
		q.pop();

		if (u == t) return w;

		for (auto& edge : adj[u]) {
			if (dist[edge.first] == -1) {
				dist[edge.first] = w + edge.second;
				q.push({ edge.first, dist[edge.first] });
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		cout << solve(u, v) << '\n';
	}
}