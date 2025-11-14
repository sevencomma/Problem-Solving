#include <bits/stdc++.h>
using namespace std;

struct edge {
	int v, c, d;
};

bool compare(edge& a, edge& b) {
	return a.d < b.d;
}

struct dat {
	int n, c, d;
};

struct cmp {
	bool operator() (dat& a, dat& b) const {
		return a.d > b.d;
	}
};

int T, N, M, K, u, v, c, d;
vector <edge> adjs[101]; // {v, {c, d}}

int cache[101][10001]; // n, m

int dijkstra() {
	memset(cache, -1, sizeof(cache));
	priority_queue<dat, vector<dat>, cmp> pq;
	pq.push({ 1, 0, 0 });
	cache[1][0] = 0;

	while (!pq.empty()) {
		dat cur = pq.top();
		pq.pop();

		if (cache[cur.n][cur.c] < cur.d) continue;
		if (cur.n == N) return cur.d;

		for (auto& next : adjs[cur.n]) {

			if (cur.c + next.c > M) continue;
			if (cache[next.v][cur.c + next.c] == -1 ||
				cache[next.v][cur.c + next.c] > cur.d + next.d) {
				pq.push({ next.v, cur.c + next.c, cur.d + next.d });
				cache[next.v][cur.c + next.c] = cur.d + next.d;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
			adjs[i].clear();
		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;
			adjs[u].push_back({ v, c, d });
		}
		
		for (auto& it : adjs)
			sort(it.begin(), it.end(), compare);

		int res = dijkstra();
		if (res == -1)
			cout << "Poor KCM\n";
		else
			cout << res << '\n';

	}
}