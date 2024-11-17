#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> a;

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		if (N % i == 0)
			a.push_back(i);

	if (a.size() >= K)
		cout << a[K - 1];
	else 
		cout << 0;
}