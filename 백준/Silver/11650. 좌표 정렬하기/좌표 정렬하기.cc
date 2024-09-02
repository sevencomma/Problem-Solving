#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

bool compare(const point& a, const point& b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(void)
{
	int n;
	cin >> n;

	vector<point> points;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		points.push_back({ x,y });
	}

	sort(points.begin(), points.end(), compare);

	for (auto& it : points)
		cout << it.x << " " << it.y << "\n";
}