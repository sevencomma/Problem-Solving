#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, R, Q, u, v, q;

unordered_map<int, vector<int>> graph;
int parent[100001];
bool visited[100001];
int dp[100001];

void dfs(int node) {
	int sum = 0;
	for (auto& it : graph[node]) {
		if (!visited[it]) {
			visited[it] = true;
			dfs(it);
			sum += dp[it];
		}
	}
	dp[node] = sum + 1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	visited[R] = true;
	dfs(R);
	for (int i = 0; i < Q; i++) {
		cin >> q;
		cout << dp[q] << '\n';
	}
}