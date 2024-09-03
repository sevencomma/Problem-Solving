#include <bits/stdc++.h>
using namespace std;

bool visited[101];

int bfs(int start, vector<vector<int>>& graph)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int count = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (auto& it : graph[temp]) {
			if (visited[it])
				continue;
			q.push(it);
			visited[it] = true;
			count++;
		}
	}
	return count;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(1, graph);
}