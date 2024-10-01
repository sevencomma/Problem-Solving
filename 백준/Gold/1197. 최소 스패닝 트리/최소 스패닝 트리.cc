#include <bits/stdc++.h>
using namespace std;

struct point {
	int node1, node2, weight;

	bool operator < (point a) const {
		return weight > a.weight;
	}
};

int V, E;
priority_queue<point> pq;
int parent[10001];
int Rank[10001];

void Link(int x, int y) {
	if (Rank[x] > Rank[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y] = Rank[x] + 1;
	}
}

int Find(int x) {
	if (parent[x] != x)
		parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int Kruskal() {
	int res = 0;
	while (!pq.empty()) {
		point cur = pq.top();
		pq.pop();

		if (Find(cur.node1) == Find(cur.node2))
			continue;
		Union(cur.node1, cur.node2);
		res += cur.weight;
	}
	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i <= V; i++)
		parent[i] = i;
	int a, b, w;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> w;
		pq.push({ a, b, w });
	}
	cout << Kruskal();
}