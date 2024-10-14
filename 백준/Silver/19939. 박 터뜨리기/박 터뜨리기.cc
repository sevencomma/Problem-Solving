#include <bits/stdc++.h>
using namespace std;

int rev[1001];

int main(void) {
	int n, k;
	cin >> n >> k;

	if (n < k * (k + 1) / 2)
		cout << -1;
	else if (n == k * (k + 1) / 2)
		cout << k - 1;
	else {
		int temp = n - k * (k + 1) / 2;
		if (temp % k == 0)
			cout << k - 1;
		else
			cout << k;
	}
}