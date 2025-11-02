#include <bits/stdc++.h>
using namespace std;

struct info {
	int node, kaka, bebe;
};

struct cmp {
	bool operator() (info& a, info& b) const {
		return a.bebe > b.bebe;
	}
};

int N, M, a, b, c, d;
vector<info> adjs[1000];

int weights[1000][1001]; // {node}{sum kaka} -> sum bebe

int solve() {	// 0 -> N - 1
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= 1000; j++)
			weights[i][j] = INT_MAX;

	vector<int> res; // stress (= sum kaka * sum bebe)
	priority_queue<info, vector<info>, cmp> pq;
	pq.push({ 0, 0, 0 });
	weights[0][0] = 0;

	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();

		if (weights[cur.node][cur.kaka] < cur.bebe)
			continue;
		
		if (cur.node == N - 1) {
			res.push_back(cur.kaka * cur.bebe);
			continue;
		}

		for (auto& next : adjs[cur.node]) {
			if (cur.kaka + next.kaka > 1000 || cur.bebe + next.bebe > 1000) continue;
			if (weights[next.node][cur.kaka + next.kaka] <= cur.bebe + next.bebe) continue;
			pq.push({ next.node, cur.kaka + next.kaka, cur.bebe + next.bebe });
			weights[next.node][cur.kaka + next.kaka] = cur.bebe + next.bebe;
		}
	}

	if (res.empty()) return -1;
	sort(res.begin(), res.end());
	return res[0];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		adjs[a].push_back({ b, c, d });
		adjs[b].push_back({ a, c, d });
	}

	cout << solve();
}