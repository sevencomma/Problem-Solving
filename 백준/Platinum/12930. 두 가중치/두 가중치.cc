#include <bits/stdc++.h>
using namespace std;

struct dat {
	int n, w1, w2;
};

struct cmp {
	bool operator() (dat& a, dat& b) {
		return a.w1 * a.w2 > b.w1 * b.w2;
	}
};

int N;
int weight1[20][20];
int weight2[20][20];
int dist[20][181][181];

int dijkstra() {
	priority_queue<dat, vector<dat>, cmp> pq;
	pq.push({ 0, 0, 0 });
	dist[0][0][0] = 0;

	while (pq.size()) {
		dat cur = pq.top();
		pq.pop();

		if (cur.w1 * cur.w2 > dist[cur.n][cur.w1][cur.w2])
			continue;

		for (int i = 0; i < N; i++) {
			if (weight1[cur.n][i] == 0) continue;
			int nw1 = cur.w1 + weight1[cur.n][i];
			int nw2 = cur.w2 + weight2[cur.n][i];

			if (nw1 > 180 || nw2 > 180) continue;

			if (dist[i][nw1][nw2] > nw1 * nw2) {
				pq.push({ i, nw1, nw2 });
				dist[i][nw1][nw2] = nw1 * nw2;
			}
		}
	}
	
	int ret = INT_MAX;
	for (int i = 0; i <= 180; i++)
		for (int j = 0; j <= 180; j++)
			ret = min(ret, dist[1][i][j]);
	if (ret == INT_MAX)
		return -1;
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	char c;

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= 180; j++)
			for (int k = 0; k <= 180; k++)
				dist[i][j][k] = INT_MAX;

	for (int k = 0; k < 2; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> c;
				if (c != '.') {
					if (k == 0) weight1[i][j] = c - '0';
					else weight2[i][j] = c - '0';
				}
			}
	
	cout << dijkstra();
}