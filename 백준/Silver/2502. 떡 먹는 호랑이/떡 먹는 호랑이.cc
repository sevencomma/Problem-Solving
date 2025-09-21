#include <bits/stdc++.h>
using namespace std;

int D, K;
int fib[31];

void solve(int a, int b) {
	memset(fib, 0, sizeof(fib));
	fib[1] = a;
	fib[2] = b;

	for (int i = 3; i <= D; i++)
		fib[i] = fib[i - 2] + fib[i - 1];
}

int main(void) {
	cin >> D >> K;

	for (int i = 1; i <= K; i++)
		for (int j = i; j <= K; j++) {
			solve(i, j);
			if (fib[D] == K) {
				cout << i << '\n' << j;
				return 0;
			}
			else if (fib[D] > K)
				break;
		}
}