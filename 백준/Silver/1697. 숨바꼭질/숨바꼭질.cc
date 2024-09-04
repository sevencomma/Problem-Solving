#include <bits/stdc++.h>
using namespace std;

int visited[200000];

int dx[3] = { 1, -1, 0 };

struct point {
	int x, cnt;
};

bool is_in_range(int x) {
	return (x >= 0 && x < 200000);
}

int bfs(int start, int target)
{
	queue<point> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.x == target)
			return cur.cnt;
		for (int i = 0; i < 3; i++) {
			int cx = cur.x + dx[i];
			if (i == 2)
				cx *= 2;
			if (!is_in_range(cx) || visited[cx])
				continue;

			q.push({ cx, cur.cnt + 1 });
			visited[cx] = true;
		}
	}
}
int main(void)
{
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
}