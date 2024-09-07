#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> roads;
vector<int> order;

bool compare(int a, int b) {
	return order[a] < order[b];
}

bool visited[100001];
vector<int> result;
void dfs(int x) {
	visited[x] = true;
	result.push_back(x);

	for (auto& it : graph[x]) {
		if (!visited[it])
			dfs(it);
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, a, b, num;
	cin >> N;

	graph.resize(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	roads.resize(N);
	order.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> num;
		roads[i] = num;
		order[num] = i;
	}
	if (roads[0] != 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}

	dfs(1);

	for (int i = 0; i < N; i++) {
		if (roads[i] != result[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}