#include <bits/stdc++.h>
using namespace std;

int N, K;
int count_each[200000];
bool visited[200000];

bool is_in_range(int x) {
	return (x >= 0 && x < 200000);
}

int bfs(int start, int target) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	count_each[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int cnt = count_each[cur];
		int dx = cur * 2;

		if (cur == target)
			return count_each[target];
	
		while (!visited[dx] && dx < 200000)
			if (!visited[dx]) {
				q.push(dx);
				visited[dx] = true;
				count_each[dx] = cnt;
				dx *= 2;
			}
		for (int cx : {cur - 1, cur + 1})
			if (is_in_range(cx) && !visited[cx]) {
				q.push(cx);
				visited[cx] = true;
				count_each[cx] = cnt + 1;
			}
	}
}

int main(void) {
	cin >> N >> K;
	cout << bfs(N, K);
}