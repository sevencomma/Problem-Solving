#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int node, weight;
};
int N, K;
unordered_map<int, vector<int>> graph;
int visited[1001];
int weights[1001];

int bfs(int start) {
	queue<point> q;
	q.push({ start, weights[start] });
	visited[start] = weights[start];

	int res = 0;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		res = max(res, cur.weight);

		for (auto& it : graph[cur.node]) {
			if (visited[it] < cur.weight + weights[it]) {
				q.push({ it, cur.weight + weights[it] });
				visited[it] = cur.weight + weights[it];
			}
		}
	}
	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t, a, b, target;
	cin >> t;
	for (int i = 0; i < t; i++) {
		graph.clear();
		memset(visited, 0, sizeof(visited));
		memset(weights, 0, sizeof(weights));
		cin >> N >> K;
		for (int j = 1; j <= N; j++)
			cin >> weights[j];
		for (int j = 0; j < K; j++) {
			cin >> a >> b;
			graph[b].push_back(a);
		}
		cin >> target;
		cout << bfs(target) << "\n";
	}
}