#include <bits/stdc++.h>
using namespace std;

struct dat {
	int n, w;
};

struct cmp {
	bool operator() (dat& a, dat& b) {
		return a.w > b.w;
	}
};

int N, M, a, b, c, X, Y, Z;
vector<pair<int, int>> adjs[100001];
int dist[100001];

int dijkstra(int s, int t, int nope) {
	for (int i = 1; i <= N; i++)
		dist[i] = INT_MAX;

	priority_queue<dat, vector<dat>, cmp> pq;
	pq.push({ s, 0 });
	dist[s] = 0;
	dist[nope] = 0;

	while (pq.size()) {
		dat cur = pq.top();
		pq.pop();

		if (dist[cur.n] < cur.w)
			continue;

		for (auto& next : adjs[cur.n]) {
			if (dist[next.first] > cur.w + next.second) {
				pq.push({ next.first, cur.w + next.second });
				dist[next.first] = cur.w + next.second;
			}
		}
	}

	if (dist[t] == INT_MAX)
		return -1;
	return dist[t];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adjs[a].push_back({ b, c });
	}
	cin >> X >> Y >> Z;

	a = dijkstra(X, Y, 0);
	b = dijkstra(Y, Z, 0);
	c = dijkstra(X, Z, Y);

	if (a == -1 || b == -1)
		cout << -1;
	else
		cout << a + b;
	cout << ' ';
	if (c == -1)
		cout << -1;
	else
		cout << c;
}