#include <bits/stdc++.h>
using namespace std;

struct edge {
	int v, d;
	bool isHamjung;
	bool orig;
};

int N, M, K, L, P, S, E;
int x, a, b, c;
vector<edge> graph[10001];
bool hamjung[10001];
int dist[10001][20];

struct dat {
	int n, cnt, w;
};

struct cmp {
	bool operator() (dat& a, dat& b) const {
		return a.w > b.w;
	}
};

void input() {
	cin >> N >> M >> K >> L >> P;
	for (int i = 0; i < K; i++) {	// 함정
		cin >> x;
		hamjung[x] = true;
	}

	for (int i = 0; i < M - L; i++) { // 일반 길
		cin >> a >> b >> c;
		graph[a].push_back({ b, c, false });
	}
	for (int i = 0; i < L; i++) { // 함정 길
		cin >> a >> b >> c;
		graph[a].push_back({ b, c, true, true });
		graph[b].push_back({ a, c, true, false });
	}
	cin >> S >> E;
}

int dijkstra() {
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < P * 2; j++)
			dist[i][j] = INT_MAX;

	priority_queue<dat, vector<dat>, cmp> pq;
	pq.push({ S, 0, 0 });
	dist[S][0] = 0;

	while (pq.size()) {
		dat cur = pq.top();
		pq.pop();

		if (dist[cur.n][cur.cnt] < cur.w)
			continue;

		if (hamjung[cur.n]) {// 길을 건너고 나서 cnt증가시키는 걸로
			cur.cnt = (cur.cnt + 1) % (2 * P);
		}
		// cnt가 0 ~ 9 : orig
		//	10 ~ 19 : reverse

		for (auto& next : graph[cur.n]) {
			if (next.isHamjung) {
				if (cur.cnt < P && !next.orig)
					continue;
				if (cur.cnt >= P && next.orig)
					continue;
			}

			if (dist[next.v][cur.cnt] > cur.w + next.d) {
				pq.push({ next.v, cur.cnt, cur.w + next.d });
				dist[next.v][cur.cnt] = cur.w + next.d;
			}
		}
	}

	int ret = INT_MAX;
	for (int i = 0; i < P * 2; i++)
		ret = min(ret, dist[E][i]);
	if (ret == INT_MAX)
		return -1;
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	input();
	cout << dijkstra();
}