#include <bits/stdc++.h>
using namespace std;

int N;

int solve1(int e) {
	// 1 ~ pow(10, e) - 1
	int ret = 0;

	int c = 0, s, t;
	while (c < e) {
		s = pow(10, c);
		t = pow(10, c + 1) - 1;

		ret += (t - s + 1) * (c + 1);
		c++;
	}

	return ret;
}

int solve2(int e) {
	// pow(10, e) ~ N
	int s = pow(10, e);
	return (N - s + 1) * (e + 1);
}

int main(void) {
	cin >> N;
	int e = 0;
	while (1) {
		if (pow(10, e) <= N && N < pow(10, e + 1))
			break;
		e++;
	}

	cout << solve1(e) + solve2(e);
}