#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> Graph[1001];
vector<bool> visited(1001);

void dfs(int x) {
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < Graph[x].size(); i++) {
		int y = Graph[x][i];
		if (!visited[y])
			dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start); 
	visited[start] = true; 
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < Graph[x].size(); i++) {
			int y = Graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

void graph_sort(void) {
	for (int i = 0; i < 1001; i++) {
		sort(Graph[i].begin(), Graph[i].end());
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, V;

	cin >> N >> M >> V;

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;

		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}

	graph_sort();

	dfs(V); 
	
	for (int i = 0; i < visited.size(); i++) {
		visited[i] = false;
	}
	cout << endl;

	bfs(V);
}