#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int T, N, u, v;
vector<int> parent;
bool visited[10001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		parent.resize(N + 1, -1);
		for (int i = 0; i < N - 1; i++) {
			cin >> u >> v;
			parent[v] = u;
		}
		cin >> u >> v;

		int cur = u;
		visited[cur] = true;
		while (parent[cur] != -1) {
			cur = parent[cur];
			visited[cur] = true;
		}

		cur = v;
		while (!visited[cur]) {
			cur = parent[cur];
		}
		cout << cur << '\n';

		parent.clear();
		memset(visited, 0, sizeof(visited));
	}
}