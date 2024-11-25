#include <bits/stdc++.h>
using namespace std;

int T, H, W, N;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		int a = 0, b = 0;
		a = N % H;
		if (a) {
			b = N / H + 1;
		}
		else {
			b = N / H;
			a = N / b;
		}
		printf("%d%02d\n", a, b);
	}
}