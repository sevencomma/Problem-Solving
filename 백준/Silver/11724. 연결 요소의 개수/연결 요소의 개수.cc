#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> graph;
bool visited[1001];

int dfs(int node) {
	if (visited[node])
		return 0;

	visited[node] = true;

	for (auto& it : graph[node]) {
		if (!visited[it])
			dfs(it);
	}

	return 1;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int count = 0;
	for (int i = 1; i <= N; i++)
		count += dfs(i);

	cout << count;
}