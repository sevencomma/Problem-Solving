#include <bits/stdc++.h>
using namespace std;

struct point {
	int pos, weight;
};

struct cmp {
	bool operator() (point &a, point &b) const {
		return a.weight > b.weight;
	}
};

int N, M, a, b, w, S, T;
vector<vector<point>> graph(1001);
int weight[1001];
int parent[1001];

void bfs() {
	priority_queue<point, vector<point>, cmp> q;
	q.push({ S, 0 });
	weight[S] = 0;

	while (!q.empty()) {
		point cur = q.top();
		q.pop();

		if (cur.weight > weight[cur.pos])
			continue;

		for (auto& it : graph[cur.pos]) {
			if (weight[it.pos] > cur.weight + it.weight) {
				q.push({ it.pos, cur.weight + it.weight });
				weight[it.pos] = cur.weight + it.weight;
				parent[it.pos] = cur.pos;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		weight[i] = INT_MAX;
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
	} cin >> S >> T;
	bfs();

	cout << weight[T] << '\n';

	stack<int> res;
	int index = T;
	res.push(T);
	while (parent[index] != S) {
		index = parent[index];
		res.push(index);
	} res.push(S);

	cout << res.size() << '\n';
	while (!res.empty()) {
		cout << res.top() << ' ';
		res.pop();
	}
}