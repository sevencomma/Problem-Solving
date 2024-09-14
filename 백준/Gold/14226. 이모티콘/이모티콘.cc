#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int visited[2000];

struct save {
	int pos, dummy, cnt;
};

bool is_in_range(int x) {
	return x > 0 && x < 2000;
}

int bfs(int start, int target) {
	queue<save> q;
	q.push({ start, 0, 0 });
	visited[start]++;

	while (!q.empty()) {
		save cur = q.front();
		q.pop();
		if (cur.pos == target)
			return cur.cnt;

		if (is_in_range(cur.pos - 1) && visited[cur.pos - 1] < 200) {
			q.push({ cur.pos - 1, cur.dummy, cur.cnt + 1 });
			visited[cur.pos - 1]++;
		}
		if (cur.pos != cur.dummy) {
			q.push({ cur.pos, cur.pos, cur.cnt + 1 });
		}

		if (cur.dummy != 0)
			if (is_in_range(cur.pos + cur.dummy) && visited[cur.pos + cur.dummy] < 200) {
				q.push({ cur.pos + cur.dummy, cur.dummy, cur.cnt + 1 });
				visited[cur.pos + cur.dummy]++;
			}
	}
}

int main(void) {
	int S;
	cin >> S;
	cout << bfs(1, S) << endl;
}