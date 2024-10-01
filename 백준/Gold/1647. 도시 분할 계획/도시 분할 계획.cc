#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int node1, node2, weight;

	bool operator < (point a) const {
		return weight > a.weight;
	}
};

int N, M;
unordered_map<int, vector<pair<int, int>>> graph;
priority_queue<point> pq;
bool visited[100001];
int parent[100001];
int Rank[100001];

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
	int res = 0, max_value = 0;
	while (!pq.empty()) {
		point cur = pq.top();
		pq.pop();
		
		if (Find(cur.node1) == Find(cur.node2))
			continue;
		Union(cur.node1, cur.node2);
		max_value = max(max_value, cur.weight);
		res += cur.weight;
	}
	return res - max_value;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int a, b, w;
	for (int i = 0; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		pq.push({ a, b, w });
	}
	cout << kruskal();
}