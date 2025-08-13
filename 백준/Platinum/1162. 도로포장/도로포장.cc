#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 123456789012L

int N, M, K, a, b, c;

vector<pair<int, int>> graph[10001];
ll d[10001][21];

struct info {
	int n, k;
	ll w;
};

struct cmp {
	bool operator() (info& a, info& b) const {
		if (a.k == b.k)
			return a.w > b.w;
		return a.k < b.k;
	}
};

ll dijkstra(int n, int k) {
	priority_queue<info, vector<info>, cmp> pq;
	pq.push({ n, k, 0 });
	d[n][k] = 0;

	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();

		if (cur.w > d[cur.n][cur.k])
			continue;
		if (cur.n == N)
			continue;

		int next, w;
		for (auto& it : graph[cur.n]) {
			tie(next, w) = it;
			if (d[next][cur.k] > cur.w + w) {
				pq.push({ next, cur.k, cur.w + w });
				d[next][cur.k] = cur.w + w;
			}

			if (cur.k > 0 && d[next][cur.k - 1] > cur.w) {
				pq.push({ next, cur.k - 1, cur.w });
				d[next][cur.k - 1] = cur.w;
			}
		}
	}

	ll ret = INF;
	for (int i = 0; i <= K; i++)
		ret = min(ret, d[N][i]);
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			d[i][j] = INF;
	cout << dijkstra(1, K);
}