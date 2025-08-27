#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M, K, a, b, c;

struct point {
	int node;
	ll cost;
};

struct cmp {
	bool operator() (point& a, point& b) const {
		return a.cost > b.cost;
	}
};

vector<point> graph[1001];
priority_queue<ll> dist[1001]; // 최솟값 k개 유지, top은 그중 최댓값

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
}

void dijkstra() {
	priority_queue<point, vector<point>, cmp> pq;
	pq.push({ 1, 0 });
	dist[1].push(0);

	while (!pq.empty()) {
		point cur = pq.top();
		pq.pop();

		if (dist[cur.node].top() < cur.cost)
			continue;

		for (auto& next : graph[cur.node]) {
			ll nextCost = cur.cost + next.cost;

			if (dist[next.node].size() < K) {
				pq.push({ next.node, nextCost });
				dist[next.node].push(nextCost);
			}
			else if (dist[next.node].top() > nextCost) {
				dist[next.node].pop();
				dist[next.node].push(nextCost);
				pq.push({ next.node, nextCost });
			}
		}
	}
}

void solve() {
	dijkstra();
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K)
			cout << -1 << '\n';
		else
			cout << dist[i].top() << '\n';
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	input();
	solve();
}