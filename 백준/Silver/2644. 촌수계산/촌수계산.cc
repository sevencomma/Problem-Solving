#include <bits/stdc++.h>
using namespace std;

struct dist {
	int index, cnt;
};

bool visited[101];

int bfs(int start, int last, vector<vector<int>>& graph) {
	queue<dist> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		dist temp = q.front();
		q.pop();

		if (temp.index == last)
			return temp.cnt;

		for (auto& it : graph[temp.index]) {
			if (visited[it])
				continue;
			q.push({ it, temp.cnt + 1 });
			visited[it] = true;
		}
	}
	return -1;
}

int main(void)
{
	int n, f1, f2, m;
	cin >> n >> f1 >> f2 >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(f1, f2, graph);
}