#include <bits/stdc++.h>
using namespace std;

struct point {
	int num, cnt;
};

int go_move[101];
bool visited[101];
int N, M, a, b;
bool is_in_range(int pos) {
	return pos >= 1 && pos <= 100;
}
int bfs() {
	queue<point> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.num == 100)
			return cur.cnt;

		for (int i = 1; i <= 6; i++) {
			int pos = cur.num + i;
			if (is_in_range(pos)) {
				pos = go_move[pos];
				if (!visited[pos]) {
					q.push({ pos, cur.cnt + 1 });
					visited[pos] = true;
				}
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i <= 100; i++)
		go_move[i] = i;
	for (int i = 0; i < N + M; i++) {
		cin >> a >> b;
		go_move[a] = b;
	}
	cout << bfs();
}