#include <bits/stdc++.h>
using namespace std;

int x, y;
bool visited[150002];
int memo_past[150002];
vector<int> answer;

struct point {
	int pos, cnt;
};

bool is_in_range(int cx) {
	return (cx >= 0 && cx < 150000);
}
int bfs(int start, int target) {
	queue<point> q;
	q.push({ start, 0});
	visited[start] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.pos == target)
			return cur.cnt;

		for (int loc : {cur.pos + 1, cur.pos - 1, cur.pos * 2}) {
			if (!is_in_range(loc) || visited[loc])
				continue;
			q.push({ loc, cur.cnt + 1});
			visited[loc] = true;
			memo_past[loc] = cur.pos;
		}
	}
}

int main(void) {
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> x >> y;
	for (int i = 0; i < 150001; i++)
		memo_past[i] = -1;

	cout << bfs(x, y) << "\n";
	if (x == y) {
		cout << x;
		return 0;
	}

	answer.push_back(y);
	int k = 0;
	while (memo_past[answer[k]] != x) {
		answer.push_back(memo_past[answer[k]]);
		k++;
	}
	answer.push_back(x);
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i] << " ";
}