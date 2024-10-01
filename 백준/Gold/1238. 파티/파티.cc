#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge {
	int node, weight;
};
int N, M, X;
unordered_map<int, vector<edge>> graph;
int visited[1001];

int bfs(int start, int target) {
	for (int i = 0; i <= N; i++)
		visited[i] = 123456789;
	queue<edge> q;
	q.push({ start, 0 });
	visited[start] = 0;

	while (!q.empty()) {
		edge cur = q.front();
		q.pop();

		for (auto& it : graph[cur.node]) {
			if (visited[it.node] > cur.weight + it.weight) {
				q.push({ it.node, cur.weight + it.weight });
				visited[it.node] = cur.weight + it.weight;
			}
		}
	}
	return visited[target];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> X;
	int a, b, w;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int go_ = bfs(i, X);
		int come_ = bfs(X, i);
		res = max(res, go_ + come_);
	}
	cout << res;
}