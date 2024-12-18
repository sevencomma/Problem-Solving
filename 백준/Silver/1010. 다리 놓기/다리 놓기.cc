#include <bits/stdc++.h>
using namespace std;

long long res(int a, int b) {
	if (b <= 2 * a)
		a = b - a;
	long long ans = 1;
	for (int i = 0; i < a; i++) {
		ans = ans * (b - i) / (i + 1);
	}
	return ans;
}

int main(void) {
	int T, a, b;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << res(a, b) << '\n';
	}
}