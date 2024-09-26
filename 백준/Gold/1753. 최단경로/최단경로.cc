#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node {
	int node, weight;
};

struct cmp {
	bool operator() (node a, node b) const {
		return a.weight > b.weight;
	}
};

int V, E, K;
int min_d[20001];
bool visited[20001];
unordered_map<int, vector<node>> graph;

void bfs() {
	priority_queue<node, vector<node>, cmp> q;
	q.push({ K, 0 });
	min_d[K] = 0;
	visited[K] = true;

	while (!q.empty()) {
		node cur = q.top();
		q.pop();

		for (auto& it : graph[cur.node])
			if (min_d[it.node] > it.weight + cur.weight) {
				q.push({ it.node, it.weight + cur.weight});
				min_d[it.node] = it.weight + cur.weight;
			}
	}
}

int main(void) {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++)
		min_d[i] = INT_MAX;
	bfs();

	for (int i = 1; i <= V; i++)
		if (min_d[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << min_d[i] << "\n";
}