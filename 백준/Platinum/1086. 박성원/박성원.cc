#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K, TARGET;
vector<string> arr;
vector<int> len, rem, p10;

ll cache[1 << 15 + 1][100];

void save_mod() {
	for (int i = 0; i < N; i++) {
		string& t = arr[i];
		int r = 0;
		for (char c : t)
			r = (r * 10 + (c - '0')) % K;
		rem[i] = r;
	}
}

void save_pow10() {
	p10.resize(60);
	p10[0] = 1;
	for (int i = 1; i <= 59; i++)
		p10[i] = (p10[i - 1] * 10) % K;
}

int concat_rem(int r, int i) {
	return ((ll)r * p10[len[i]] + rem[i]) % K;
}

ll dp(int key, int r) {
	if (key == TARGET)
		return (r == 0) ? 1 : 0;
	ll& ret = cache[key][r];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < N; i++) {
		if (key & (1 << i)) continue;

		int newR = concat_rem(r, i);
		ret += dp(key | (1 << i), newR);
	}
	return ret;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void ans(ll p) {
	ll q = 1;
	for (int i = 1; i <= N; i++)
		q *= i;

	ll g = gcd(p, q);
	p /= g;
	q /= g;
	cout << p << "/" << q;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N + 1);
	len.resize(N + 1);
	rem.resize(N + 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> K;

	memset(cache, -1, sizeof(cache));
	TARGET = (1 << N) - 1;

	for (int i = 0; i < N; i++)
		len[i] = arr[i].length();
	save_mod();
	save_pow10();

	ll p = dp(0, 0);
	ans(p);
}