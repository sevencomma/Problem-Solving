#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int node;

	bool operator < (point a) const {
		return node > a.node;
	}
};

int N, M, a, b;
unordered_map<int, vector<int>> graph;
priority_queue<point> pq;
int in_degree[32001];
bool visited[32001];
vector<int> res;

void topological_sort() {
	for (int i = 1; i <= N; i++)
		if (in_degree[i] == 0)
			pq.push({ i });

	while (!pq.empty()) {
		point cur = pq.top();
		pq.pop();
		res.push_back(cur.node);

		for (auto& it : graph[cur.node]) {
			in_degree[it]--;
			if (in_degree[it] == 0)
				pq.push({ it });
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		in_degree[b]++;
	}
	topological_sort();
	for (auto& it : res)
		cout << it << ' ';
}