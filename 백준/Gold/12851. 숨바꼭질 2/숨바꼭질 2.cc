#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct point {
	int index, cnt;
};

int N, K;
bool visited[120000];
int count_c[120000];
int min_res;
int count_res;

int bfs() {
	queue<point> q;
	q.push({ N, 0 });
	visited[N] = true;
	count_c[N] = 1;
	unordered_map<int, int> w;
	int s = 1;
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.cnt == s) {
			s++;
			for (auto& it : w) {
				count_c[it.first] += it.second;
			}
			w.clear();
		}
		if (cur.index == K) {
			return cur.cnt;
		}

		for (auto cx : { cur.index - 1, cur.index + 1, cur.index * 2 }) {
			if (cx >= 0 && cx < 120000) {
				if (!visited[cx]) {
					q.push({ cx, cur.cnt + 1 });
					visited[cx] = true;
				}
				w[cx] += count_c[cur.index];
			}
		}
	}
	return 0;
}
int main(void) {
	cin >> N >> K;
	cout << bfs() << "\n" << count_c[K];
	cout << "\n";
}