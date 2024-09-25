#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// 2가지 case
// 1 - v1 - v2 - N
// 1 - v2 - v1 - N
struct point {
	int node, weight;
};

struct cmp {
	bool operator() (point a, point b) const {
		return a.weight > b.weight;
	}
};

bool compare(point a, point b) {
	return a.weight < b.weight;
}

int N, E, v1, v2;
unordered_map<int, vector<point>> graph;
int min_road[801];

int bfs(int start, int target) {
	for (int i = 1; i <= N; i++)
		min_road[i] = INT_MAX;
	priority_queue<point, vector<point>, cmp> q;
	q.push({ start, 0 });
	min_road[start] = 0;

	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		for (auto& it : graph[cur.node]) {
			if (min_road[it.node] > min_road[cur.node] + it.weight) {
				q.push({ it.node, cur.weight + it.weight });
				min_road[it.node] = min_road[cur.node] + it.weight;
			}
		}
	}
	if (min_road[target] == INT_MAX)
		return -1;
	else
		return min_road[target];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end(), compare);
	int d1 = 0, d2 = 0;
	int x, y, z;
	x = bfs(1, v1), y = bfs(v1, v2), z = bfs(v2, N);
	if (x == -1 || y == -1 || z == -1)
		d1 = INT_MAX;
	else
		d1 = x + y + z;
	x = bfs(1, v2), y = bfs(v2, v1), z = bfs(v1, N);
	if (x == -1 || y == -1 || z == -1)
		d2 = INT_MAX;
	else
		d2 = x + y + z;
	if (min(d1, d2) == INT_MAX)
		cout << -1;
	else 
		cout << min(d1, d2);
}