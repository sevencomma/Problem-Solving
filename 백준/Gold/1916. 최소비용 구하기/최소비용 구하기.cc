#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int pos, weight;
};

struct cmp {
	bool operator() (point a, point b) const {
		return a.weight > b.weight;
	}
};

int N, M, start, target;
unordered_map<int, vector<point>> graph;
int weight[1001];

int bfs() {
	priority_queue<point, vector<point>, cmp> q;
	q.push({ start, 0 });
	weight[start] = 0;

	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		if (cur.pos == target)
			return cur.weight;

		for (auto& it : graph[cur.pos]) {
			if (weight[it.pos] > cur.weight + it.weight) {
				q.push({ it.pos, cur.weight + it.weight });
				weight[it.pos] = cur.weight + it.weight;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
	}
	cin >> start >> target;

	for (int i = 0; i <= 1000; i++)
		weight[i] = INT_MAX;
	cout << bfs();
}