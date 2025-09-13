#include <bits/stdc++.h>
using namespace std;

int V, E, a, b;
vector<int> adj[10001];
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int cur, bool isRoot) {
	discovered[cur] = counter++;
	int ret = discovered[cur];

	int children = 0;
	for (auto& next : adj[cur]) {
		if (discovered[next] == -1) {
			children++;
			int subtree = findCutVertex(next, false);
			if (!isRoot && subtree >= discovered[cur])
				isCutVertex[cur] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[next]);
	}

	if (isRoot) isCutVertex[cur] = (children >= 2);
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	discovered.resize(V + 1, -1);
	isCutVertex.resize(V + 1, false);
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		if (discovered[i] == -1)
			findCutVertex(i, true);

	int cnt = 0;
	for (auto it : isCutVertex)
		if (it) cnt++;
	cout << cnt << '\n';
	for (int i = 1; i <= V; i++)
		if (isCutVertex[i])
			cout << i << ' ';
}