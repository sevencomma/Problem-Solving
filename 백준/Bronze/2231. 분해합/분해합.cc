#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int sum = i, temp = i;

		while (temp >= 10) {
			sum += temp % 10;
			temp /= 10;
		}
		sum += temp;
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}