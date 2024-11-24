#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[91];

int main(void) {
	fib[1] = 1;
	int N; cin >> N;
	for (int i = 2; i <= N; i++)
		fib[i] = fib[i - 2] + fib[i - 1];
	cout << fib[N];
}