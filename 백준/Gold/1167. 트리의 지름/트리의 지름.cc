#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge {
	int node, weight;
};

unordered_map<int, vector<edge>> tree;
bool visited[100001];
int max_d;
int max_n;
void dfs(int node, int len) {
	if (max_d < len) {
		max_d = len;
		max_n = node;
	}

	for (auto& it : tree[node])
		if (!visited[it.node]) {
			visited[it.node] = true;
			dfs(it.node, len + it.weight);
			visited[it.node] = false;
		}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		int n; cin >> n;
		while (1) {
			int a, w;
			cin >> a;
			if (a == -1)
				break;
			cin >> w;
			tree[n].push_back({ a, w });
		}
	}
	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;
	visited[max_n] = true;
	dfs(max_n, 0);
	cout << max_d;
}