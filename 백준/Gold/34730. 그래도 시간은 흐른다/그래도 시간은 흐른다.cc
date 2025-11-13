#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct dat {
	int n, c, w;
};

struct info {
	int n;
	ll t;
};

struct cmp {
	bool operator() (info& a, info& b) const {
		return a.t > b.t;
	}
};

int N, M, K, S, T;
vector<dat> adjs[100001];
ll cache[100001][30]; // {node, t % K}

ll dijkstra() {
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < K; j++)
			cache[i][j] = LLONG_MAX;

	priority_queue<info, vector<info>, cmp> pq;
	pq.push({ S, 0 });
	cache[S][0] = 0;

	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();

		if (cache[cur.n][cur.t % K] < cur.t) continue;
		if (cur.n == T) return cur.t;
	
		for (auto& next : adjs[cur.n]) {
			if (cur.t % next.w != 0) continue;
			if (cache[next.n][(cur.t + next.c) % K] <= cur.t + next.c) continue;
			pq.push({ next.n, cur.t + next.c });
			cache[next.n][(cur.t + next.c) % K] = cur.t + next.c;
		}
	}

	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K >> S >> T;
	
	for (int i = 0; i < M; i++) {
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		adjs[u].push_back({ v, c, w });
	}
	cout << dijkstra();
}