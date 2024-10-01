#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, M, K, temp;
unordered_map<int, int> truth_friend;
unordered_map<int, vector<int>> graph;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		truth_friend[temp]++;
	}

	vector<vector<int>> party_member(M);
	for (int i = 0; i < M; i++) {
		cin >> K;
		party_member[i].resize(K);
		for (int j = 0; j < K; j++) {
			cin >> party_member[i][j];
		}
	}

	for (auto& it : party_member) {
		for (int i = 0; i < it.size() - 1; i++) {
			graph[it[i]].push_back(it[i + 1]);
			graph[it[i + 1]].push_back(it[i]);
		}
	}

	bool visited[51] = { false, };
	queue<int> q;
	for (auto& it : truth_friend) {
		q.push(it.first);
		visited[it.first] = true;
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		truth_friend[cur]++;

		for (auto& it : graph[cur]) {
			if (!visited[it]) {
				q.push(it);
				visited[it] = true;
			}
		}
	}

	int count = 0;
	for (auto& it1 : party_member) {
		bool truth = false;
		for (auto& it2 : it1) {
			if (truth_friend[it2] > 0)
				truth = true;
		}
		if (!truth)
			count++;
	}
	cout << count;
}