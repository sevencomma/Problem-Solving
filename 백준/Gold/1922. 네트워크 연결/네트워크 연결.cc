#include <bits/stdc++.h>
using namespace std;

struct edge {
	int node1, node2, weight;

	bool operator < (const edge a) const {
		return weight > a.weight;
	}
};

int N, M, a, b, w;
int parent[1001];
int Rank[1001];
priority_queue<edge> pq;

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

int kruskal() {
	int res = 0;
	while (!pq.empty()) {
		edge cur = pq.top();
		pq.pop();

		if (Find(cur.node1) != Find(cur.node2)) {
			Union(cur.node1, cur.node2);
			res += cur.weight;
		}
	}
	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		pq.push({ a, b, w });
	}
	cout << kruskal();
}