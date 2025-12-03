#include <bits/stdc++.h>
#include <bit>
using namespace std;

int N, K, res;

int main(void) {
	cin >> N >> K;

	while (1) {
		int count = popcount((unsigned int)(N + res));

		if (count <= K)
			break;
		res++;
	}
	cout << res;
}