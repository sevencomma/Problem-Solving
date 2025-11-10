#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001

int N, M, a, b;
int parent[MAX_N];
vector<int> children[MAX_N];
int weights[MAX_N];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> parent[i];
		if (parent[i] != -1)
			children[parent[i]].push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		weights[a] += b;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		auto [idx, val] = q.front();
		q.pop();

		weights[idx] += val;
		for (auto& next : children[idx]) {
			q.push({ next, weights[idx] });
		}
	}

	for (int i = 1; i <= N; i++)
		cout << weights[i] << ' ';
}