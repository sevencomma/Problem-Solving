#include <bits/stdc++.h>
using namespace std;
// 사이클이 1개라고 가정?

bool visited[3001];
bool cycle[3001];

struct road {
	int index;
	vector<int> roads;
};

int dfs(int start, vector<vector<int>> &graph) {
	if (cycle[start])
		return 0;

	stack<road> s;
	s.push({ start, {start}});

	while (!s.empty()) {
		road cur = s.top();
		s.pop();
		visited[cur.index] = true;
		for (auto& it : graph[cur.index]) {
			if (it == start && cur.roads.size() > 2) {
				for (int i = 0; i < cur.roads.size(); i++) {
					cycle[cur.roads[i]] = true;
				}
				return 1;
			}
			if (visited[it])
				continue;
			cur.roads.push_back(it);
			s.push({ it,  cur.roads});
			cur.roads.pop_back();
		}
	}
	return -1;
}

struct distance_ {
	int index, cnt;
};

int bfs(int start, vector<vector<int>>& graph) {
	if (cycle[start])
		return 0;

	queue<distance_> q;
	visited[start] = true;
	q.push({ start, 0 });

	while (!q.empty()) {
		distance_ cur = q.front();
		q.pop();

		if (cycle[cur.index])
			return cur.cnt;

		for (auto& it : graph[cur.index]) {
			if (visited[it])
				continue;

			q.push({ it, cur.cnt + 1 });
			visited[it] = true;
		}
	}
	return -1;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i, graph) == 1) {
			break;
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		cout << bfs(i, graph) << " ";
	}
}