#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(int start, vector<bool> &visited, vector<int> &check_two, unordered_map<int, vector<int>>& graph) {
	if (visited[start] == true)
		return 0;

	queue<int> q;

	q.push(start);
	check_two[start] = 1;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		visited[temp] = true;

		for (auto &it : graph[temp]) {
			if (!visited[it]) {
				if (check_two[it] != 0 && check_two[it] == check_two[temp])
					return -1;

				q.push(it);
				if (check_two[temp] == 1)
					check_two[it] = 2;
				else
					check_two[it] = 1;
				
			}
			else {
				if (check_two[temp] == check_two[it])
					return -1;
			}
		}

	}
	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	for (int c = 0; c < K; c++) {
		unordered_map<int, vector<int>> graph;
		int V, E;
		cin >> V >> E;

		for (int i = 0; i < V; i++)
			graph[i + 1] = {};

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<bool> visited(graph.size() + 1, false);
		vector<int> check_two(graph.size() + 1, 0);

		bool check = true;
		for (int i = 1; i <= V; i++) {
			int ans = bfs(i, visited, check_two, graph);

			if (ans == -1) {
				cout << "NO\n";
				check = false;
				break;
			}
		}
		if (check)
			cout << "YES\n";
	}
}