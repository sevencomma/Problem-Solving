#include <bits/stdc++.h>
using namespace std;

bool is_prime[10001];

int main(void) {
	int M, N;
	cin >> M >> N;

	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;

	for (int i = 2; i * i <= 10000; i++)
		if (is_prime[i])
			for (int j = i * i; j <= 10000; j += i)
				is_prime[j] = false;

	int sum = 0;
	int min = 100000;
	for (int i = M; i <= N; i++)
		if (is_prime[i]) {
			sum += i;
			if (min > i)
				min = i;
		}
	if (min == 100000) {
		cout << -1;
		return 0;
	}
	cout << sum << endl << min;
}