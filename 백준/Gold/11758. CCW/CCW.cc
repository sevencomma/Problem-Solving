#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

int ccw(point a, point b, point c) {
	int S = a.x * b.y + b.x * c.y + c.x * a.y;
	S -= (a.y * b.x + b.y * c.x + c.y * a.x);
	
	if (S > 0) return 1;
	else if (S == 0) return 0;
	else return -1;
}

int main(void) {
	point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << ccw(a, b, c);
}