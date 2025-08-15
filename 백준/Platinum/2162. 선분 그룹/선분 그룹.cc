#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Point {
	int x, y;

	auto operator<=>(const Point&) const = default;
};

int ccw(Point& a, Point& b, Point& c) {
	long long op = 1L * (b.x - a.x) * (c.y - a.y)
				 - 1L * (b.y - a.y) * (c.x - a.x);
	if (op > 0) return 1;
	if (op < 0) return -1;
	return 0;
}

bool isCrossed(Point& A, Point& B, Point& C, Point& D) {
	int std1, std2;

	std1 = ccw(A, B, C) * ccw(A, B, D);
	std2 = ccw(C, D, A) * ccw(C, D, B);

	if (std1 <= 0 && std2 <= 0) {
		if (std1 == 0 && std2 == 0) {
			auto a0 = min(A, B);
			auto a1 = max(A, B);
			auto b0 = min(C, D);
			auto b1 = max(C, D);

			// 터치 포함 겹침
			return !(a1 < b0 || b1 < a0); // == (a0 <= b1 && b0 <= a1)
		}
		return true;
	}

	return false;
}

int N, a, b, c, d;
vector<pair<Point, Point>> lines;
int Parent[3000];
int Rank[3000];

void Link(int x, int y) {
	if (Rank[x] > Rank[y])
		Parent[y] = x;
	else {
		Parent[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y]++;
	}
}

int Find(int x) {
	if (Parent[x] != x)
		Parent[x] = Find(Parent[x]);
	return Parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		lines.push_back({ {a,b}, {c, d} });
		Parent[i] = i;
	}

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			if (Find(i) == Find(j))
				continue;

			if (isCrossed(lines[i].first, lines[i].second, lines[j].first, lines[j].second))
				Union(i, j);
		}

	unordered_map<int, int> cnt;
	for (int i = 0; i < N; i++)
		cnt[Find(i)]++;

	cout << cnt.size() << '\n';
	int res = 0;
	for (auto& it : cnt)
		res = max(res, it.second);
	cout << res;
}