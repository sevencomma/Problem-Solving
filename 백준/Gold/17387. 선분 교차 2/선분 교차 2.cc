#include <bits/stdc++.h>
using namespace std;

struct point {
	long long x, y;

	bool operator <= (point P) {
		if (x == P.x)
			return y <= P.y;
		return x <= P.x;
	}
};

int ccw(point a, point b, point c) {
	long long S = a.x * b.y + b.x * c.y + c.x * a.y;
	S -= (a.y * b.x + b.y * c.x + c.y * a.x);

	if (S > 0) return 1;
	else if (S == 0) return 0;
	else return -1;
}

point a, b, c, d;

int main(void) {
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;

	int p1, p2, p3, p4;
	p1 = ccw(a, b, c), p2 = ccw(a, b, d);
	p3 = ccw(c, d, a), p4 = ccw(c, d, b);

	int K1, K2;
	K1 = p1 * p2, K2 = p3 * p4;
	if (K1 == 0 && K2 == 0) {
		if (b <= a) swap(a, b);
		if (d <= c) swap(c, d);

		if (a <= d && c <= b)
			cout << 1;
		else
			cout << 0;
	}
	else if (K1 <= 0 && K2 <= 0) {
		cout << 1;
	}
	else
		cout << 0;
}