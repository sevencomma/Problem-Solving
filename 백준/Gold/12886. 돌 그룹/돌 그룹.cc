#include <bits/stdc++.h>
using namespace std;

struct point {
	int a, b, c;
};

int a, b, c;
bool visited[1001][1001];
int target;

int bfs() {
	queue<point> q;
	q.push({ a, b, c });
	visited[a][b] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.a == target && cur.b == target)
			return 1;

		// ab
		if (cur.a < cur.b && cur.a <= 500) {
			if (!visited[cur.a * 2][cur.b - cur.a]) {
				q.push({ cur.a * 2, cur.b - cur.a, cur.c });
				visited[cur.a * 2][cur.b - cur.a] = true;
			}
		}
		else if (cur.a >= cur.b && cur.b <= 500) {
			if (!visited[cur.a - cur.b][cur.b * 2]) {
				q.push({ cur.a - cur.b, cur.b * 2, cur.c });
				visited[cur.a - cur.b][cur.b * 2] = true;
			}
		}
		// bc
		if (cur.b < cur.c && cur.b <= 50) {
			if (!visited[cur.a][cur.b * 2]) {
				q.push({ cur.a, cur.b * 2, cur.c - cur.b });
				visited[cur.a][cur.b * 2] = true;
			}
		}
		else if (cur.b >= cur.c && cur.c <= 500) {
			if (!visited[cur.a][cur.b - cur.c]) {
				q.push({ cur.a, cur.b - cur.c, cur.c * 2 });
				visited[cur.a][cur.b - cur.c] = true;
			}
		}

		// ca
		if (cur.a < cur.c && cur.a <= 500) {
			if (!visited[cur.a * 2][cur.b]) {
				q.push({ cur.a * 2, cur.b, cur.c - cur.a });
				visited[cur.a * 2][cur.b];
			}
		}
		else if (cur.a >= cur.c && cur.c <= 500) {
			if (!visited[cur.a - cur.c][cur.b]) {
				q.push({ cur.a - cur.c, cur.b, cur.c * 2 });
				visited[cur.a - cur.c][cur.b];
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> a >> b >> c;
	if ((a + b + c) % 3 != 0) {
		cout << 0;
		return 0;
	}
	target = (a + b + c) / 3;
	cout << bfs();
}