#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m, M, T, R, X;
	cin >> n >> m >> M >> T >> R;
	int count = 0;
	X = m;
	if (X + T > M) {
		cout << -1;
		return 0;
	}
	while (n > 0) {
		if (X + T <= M) {
			X += T;
			n--;
		}
		else {
			X -= R;
			if (X < m)
				X = m;
		}
		count++;
	}
	cout << count;
}