#include <bits/stdc++.h>
using namespace std;

int cnt, N, a;
int main(void) {
	cin >> N;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		if (a == N)
			cnt++;
	} cout << cnt;
}