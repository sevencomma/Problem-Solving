#include <bits/stdc++.h>
using namespace std;

int M, N, x, y, z, sum;
priority_queue<
	pair<int, pair<int, int>>,
	vector<pair<int, pair<int, int>>>,
	greater<pair<int, pair<int, int>>>>
	pq;

int Parent[200001];
int Rank[200001];

void Link(int x, int y) {
	if (Rank[x] > Rank[y])
		Parent[y] = x;
	else {
		Parent[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y]++;
	}
}

int Find(int x) {
	if (Parent[x] != x)
		Parent[x] = Find(Parent[x]);
	return Parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int kruskal() {
	int ret = 0;

	int cost, a, b;
	while (!pq.empty()) {
		cost = pq.top().first;
		tie(a, b) = pq.top().second;
		pq.pop();
		if (Find(a) != Find(b)) {
			Union(a, b);
			ret += cost;
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> M >> N;
		if (M == 0) break;
		sum = 0;
		for (int i = 0; i < M; i++)
			Parent[i] = i;
		memset(Rank, 0, sizeof(Rank));

		for (int i = 0; i < N; i++) {
			cin >> x >> y >> z;
			pq.push({ z, {x, y} });
			sum += z;
		}

		cout << sum - kruskal() << '\n';
	}
}