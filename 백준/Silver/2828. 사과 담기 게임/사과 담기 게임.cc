#include <bits/stdc++.h>
using namespace std;

int N, M, J, x, res;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> J;

	int l = 1, r = l + M - 1;

	for (int i = 0; i < J; i++) {
		cin >> x;

		if (l <= x && x <= r)
			continue;

		int diff;
		if (x < l) {
			diff = l - x;
			l -= diff;
			r -= diff;
		}
		else {
			diff = x - r;
			l += diff;
			r += diff;
		}

		res += diff;
	}
	cout << res;
}