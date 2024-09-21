#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge {
	int node, weight;
};

int max_d;
bool visited[10001];
unordered_map<int, vector<edge>> tree;
unordered_map<int, vector<int>> tree_leaf;

void dfs(int node, int len) {
	if (len > max_d)
		max_d = len;
	for (auto& it : tree[node]) {
		if (!visited[it.node]) {
			visited[it.node] = true;
			dfs(it.node, len + it.weight);
			visited[it.node] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n ; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		tree[a].push_back({ b, w });
		tree[b].push_back({ a, w });
		tree_leaf[a].push_back(b);
		tree_leaf[b].push_back(a);
	}

	vector<int> leafs;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		bool imleaf = true;
		for (auto& it : tree_leaf[cur]) {
			if (!visited[it]) {
				imleaf = false;
				q.push({ it });
				visited[it] = true;
			}
		}
		if (imleaf)
			leafs.push_back(cur);
	}

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < leafs.size(); i++) {
		visited[leafs[i]] = true;
		dfs(leafs[i], 0);
		visited[leafs[i]] = false;
	}
	cout << max_d;
}