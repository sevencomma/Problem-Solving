#include <bits/stdc++.h>
using namespace std;

bool is_prime[1000000];
vector<int> prime;

int main(void) {
	int N; cin >> N;
	int save_n = N;
	for (int i = 2; i < 1000000; i++)
		is_prime[i] = 1;
	for (int i = 2; i * i < N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j < N; j += i)
				is_prime[j] = false;
		}
	}
	for (int i = 0; i < N; i++)
		if (is_prime[i])
			prime.push_back(i);

	int size = prime.size();
	for (int a = 0; a < size; a++) {
		N -= prime[a];
		if (N >= 0) {
			for (int b = a; b < size; b++) {
				N -= prime[b];
				if (N >= 0) {
					for (int c = b; c < size; c++) {
						N -= prime[c];
						if (N >= 0) {
							if (is_prime[N]) {
								cout << prime[a] << ' ' << prime[b] << ' ' << prime[c] << ' ' << save_n - prime[a] - prime[b] - prime[c];
								return 0;
							}
						}
						N += prime[c];
					}
				}
				N += prime[b];
			}
		}
		N += prime[a];
	}
	cout << -1;
}