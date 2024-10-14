#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N, Q; cin >> N;
	Q = N / 5;
	for (int i = Q; i >= 0; i--) {
		int temp = N - 5 * i;
		if (temp % 3 == 0) {
			cout << i + temp / 3;
			return 0;
		}
	}
	cout << -1;
}