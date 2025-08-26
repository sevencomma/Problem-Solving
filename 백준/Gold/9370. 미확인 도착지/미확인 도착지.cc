#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define INF 987654321
int T, n, m, t, s, g, h, a, b, d, x;

vector<vector<pair<int, int>>> graph;
unordered_set<int> target;
int dist[2001][2]; // {off, on}

struct info {
	int node, weight;
	bool on;
};

struct cmp {
	bool operator() (info& a, info& b) {
		return a.weight > b.weight;
	}
};

void init() {
	cin >> n >> m >> t >> s >> g >> h;

	graph.clear();
	target.clear();
	graph.resize(n + 1);

	for (int i = 1; i <= n; i++)
		dist[i][0] = dist[i][1] = INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		graph[a].push_back({ b, d });
		graph[b].push_back({ a, d });
	}

	for (int j = 0; j < t; j++) {
		cin >> x;
		target.insert(x);
	}
}

set<int> dijkstra() {
	priority_queue<info, vector<info>, cmp> pq;
	pq.push({ s, 0, false });
	dist[s][0] = 0;

	set<int> ret;

	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();

		if (cur.weight > dist[cur.node][cur.on])
			continue;

		if (target.find(cur.node) != target.end() && cur.on && cur.weight <= dist[cur.node][0])
			ret.insert(cur.node);

		for (auto& next : graph[cur.node]) {
			
			bool next_on = cur.on;
			if ((cur.node == g && next.first == h) || (cur.node == h && next.first == g))
				next_on = true;

			if (dist[next.first][next_on] > cur.weight + next.second) {
				pq.push({ next.first, cur.weight + next.second, next_on });
				dist[next.first][next_on] = cur.weight + next.second;
			}
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		init();
		auto res = dijkstra();

		for (auto& it : res)
			cout << it << ' ';
		cout << '\n';
	}
}