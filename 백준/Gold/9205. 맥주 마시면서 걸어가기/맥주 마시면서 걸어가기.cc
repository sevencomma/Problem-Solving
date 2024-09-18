#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x;
};

int start_y, start_x;
int final_y, final_x;

int distance(int y, int x, int Y, int X) {
	return (abs(y - Y) + abs(x - X));
}

int cur_y, cur_x;
bool compare(point a, point b) {
	return distance(a.y, a.x, cur_y, cur_x) < distance(b.y, b.x, cur_y, cur_x);
}

bool can_go(vector<point> &node) {
	queue<point> q;
	q.push({ start_y, start_x });
	vector<bool> visited(node.size(), false);

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (distance(cur.y, cur.x, final_y, final_x) <= 1000)
			return true;

		cur_y = cur.y;
		cur_x = cur.x;

		for (int i = 0; i < node.size(); i++) {
			if (!visited[i] && distance(node[i].y, node[i].x, cur.y, cur.x) <= 1000) {
				q.push({ node[i].y, node[i].x });
				visited[i] = true;
			}
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<point> node;
		cin >> start_y >> start_x;
		for (int i = 0; i < n; i++) {
			int y, x;
			cin >> y >> x;
			node.push_back({ y, x });
		}
		cin >> final_y >> final_x;
		if (can_go(node))
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}