#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_map<int, unordered_set<int>> sequence;
int visited[32001] = { 0 };
int in_degree[32001] = { 0 };
vector<int> result;

void bfs(int start) {
	if (visited[start] != 0) {
		return ;
	}
	queue<int> q;

	q.push(start);
	visited[start]++;
	result.push_back(start);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (auto it : sequence[temp]) {
			in_degree[it]--;

			if (visited[it] == 0 && in_degree[it] == 0) {
				q.push(it);
				visited[it]++;
				result.push_back(it);
			}
		}
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	in_degree[0] = -1;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		sequence[n1].insert(n2);
		in_degree[n2]++;
	}

	vector<int> start_vertex;

	for (int i = 1; i < N + 1; i++) {
		if (in_degree[i] == 0)
			start_vertex.push_back(i);
	}

	for (int i = 0; i < start_vertex.size(); i++) {
		bfs(start_vertex[i]);
	}

	for (auto it : result) {
		cout << it << " ";
	}
}