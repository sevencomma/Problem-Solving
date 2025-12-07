#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int N;
ll cache[1000000][3];

int main(void) {
	cin >> N;

	cache[0][0] = 1;
	cache[0][1] = 1;
	cache[0][2] = 1;

	for (int i = 1; i < N; i++) {
		cache[i][0] = (cache[i - 1][1] + cache[i - 1][1] + cache[i - 1][2]) % MOD;
		cache[i][1] = (cache[i - 1][0] + cache[i - 1][1] + cache[i - 1][2]) % MOD;
		cache[i][2] = (cache[i - 1][0] + cache[i - 1][1]) % MOD;
	}

	cout << (cache[N - 1][0] + cache[N - 1][1] + cache[N - 1][2]) % MOD;
}