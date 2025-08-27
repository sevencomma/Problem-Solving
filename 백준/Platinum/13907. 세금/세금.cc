#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, M, K, S, D, a, b, w;
vector<pair<int, int>> graph[1001];
int tax[30001]; // 누적합

int dist[1001][1000]; // dist[i][j] : j 번 이동해서 i까지 가는 최소 통행료

void init() {
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = INF;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w });
	}
	for (int i = 1; i <= K; i++) {
		cin >> tax[i];
		tax[i] += tax[i - 1];
	}
}

struct info {
	int idx, cnt, cost;
};

struct cmp {
	bool operator() (info& a, info& b) const {
		if (a.cost == b.cost)
			return a.cnt > b.cnt;
		return a.cost > b.cost;
	}
};

void dijkstra() {
	priority_queue<info, vector<info>, cmp> pq;
	pq.push({ S, 0, 0 });
	dist[S][0] = 0;

	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();

		if (cur.cost > dist[cur.idx][cur.cnt]) continue;
		if (cur.cnt == N - 1) continue;

		for (auto& next : graph[cur.idx]) {
			if (dist[next.first][cur.cnt + 1] > cur.cost + next.second) {
				pq.push({ next.first, cur.cnt + 1, cur.cost + next.second });
				dist[next.first][cur.cnt + 1] = cur.cost + next.second;
			}
		}
	}
}

int getMinCost(int k) {
	int res = INF;
	for (int i = 0; i < N; i++) {
		res = min(res, dist[D][i] + tax[k] * i);
	}
	return res;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K >> S >> D;
	init();
	dijkstra();
	for (int i = 0; i <= K; i++)
		cout << getMinCost(i) << '\n';
}