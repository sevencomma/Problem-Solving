#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int N;
ll fib[1000001];

int main(void) {
	cin >> N;
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= N; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	cout << fib[N];
}