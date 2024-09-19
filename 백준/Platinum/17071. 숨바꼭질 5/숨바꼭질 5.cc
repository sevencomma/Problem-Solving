#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct pos {
	int x, cnt;
};
struct cmp {
	bool operator() (pos a, pos b) const {
		return a.cnt > b.cnt;
	}
};
int n, k;
int bro_pos[1001];
bool odd_visited[500001];
bool even_visited[500001];
unordered_map<int, int> brother;

bool is_in_range(int x, int cnt) {
	return (x >= 0 && x <= 500000 && cnt <= 1000);
}

int bfs() {
	priority_queue<pos, vector<pos>, cmp> q;
	q.push({ n, 0 });
	even_visited[n] = true;
	int prev_ans = INT_MAX;
	while (!q.empty()) {
		pos cur = q.top();
		q.pop();

		if (brother[cur.x] > 0) {
			if (cur.x == bro_pos[cur.cnt])
				return cur.cnt;
			else
				if (cur.cnt + 2 <= 1000)
					q.push({ cur.x, cur.cnt + 2 });
		}

		for (auto cx : { cur.x - 1, cur.x + 1, cur.x * 2 }) {
			if (!is_in_range(cx, cur.cnt + 1))
				continue;
			if (cur.cnt % 2 == 0)
				if (!odd_visited[cx]) {
					q.push({ cx, cur.cnt + 1 });
					odd_visited[cx] = true;
				}
			if (cur.cnt % 2 != 0)
				if (!even_visited[cx]) {
					q.push({ cx, cur.cnt + 1 });
					even_visited[cx] = true;
				}
		}
	}
	return -1;
}

int main(void) {
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= 1000; i++)
		bro_pos[i] = k + i * (i + 1) / 2;
	for (int i = 1; i <= 1000; i++) {
		if (bro_pos[i] <= 500000)
			brother[bro_pos[i]] = i;
		else
			break;
	}
	cout << bfs();
}