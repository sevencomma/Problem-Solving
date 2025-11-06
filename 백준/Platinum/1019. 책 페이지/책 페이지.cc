#include <bits/stdc++.h>
using namespace std;

int N;
long long cnt[10];

void read(int x, int depth) {
	while (x > 0) {
		cnt[x % 10] += pow(10, depth);
		x /= 10;
	}
}

void solve(int l, int r, int depth) {
	while (l % 10 != 0) {
		read(l, depth);
		l++;
		if (l > r) return;
	}
	while (r % 10 != 9) {
		read(r, depth);
		r--;
		if (r < l) return;
	}

	l /= 10;
	r /= 10;
	long long val = (r - l + 1) * pow(10, depth);
	for (int i = 0; i < 10; i++)
		cnt[i] += val;

	solve(l, r, depth + 1);
}

int main(void) {
	cin >> N;

	int n = 0;
	while (1) {
		if (N >= pow(10, n + 1))
			solve(pow(10, n), pow(10, n + 1) - 1, 0);
		else {
			solve(pow(10, n), N, 0);
			break;
		}
		n++;
	}

	for (int i = 0; i < 10; i++)
		cout << cnt[i] << ' ';
}