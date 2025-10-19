#include <bits/stdc++.h>
using namespace std;

int N, M, x, y;
priority_queue<
	pair<double, pair<int, int>>,
	vector<pair<double, pair<int, int>>>,
	greater<pair<double, pair<int, int>>>>
	pq;

vector<pair<int, int>> points;
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

double kruskal() {
	double ret = 0;

	double cost, a, b;
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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		points.push_back({ x, y });
		Parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		Union(x, y);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double cost = sqrt(
				pow(points[i].first - points[j].first, 2) + 
				pow(points[i].second - points[j].second, 2)
			);
			pq.push({ cost, { i + 1, j + 1 } });
		}
	}
	printf("%.2f\n", (double)kruskal());
}