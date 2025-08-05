#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;

bool success(int m) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += min(arr[i], m);
		if (sum > M) break;
	}
	return sum <= M;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;

	sort(arr.begin(), arr.end());
	int l = 0, r = arr.back() + 1, m;
	
	while (l < r) {
		m = (l + r) / 2;
		if (success(m)) l = m + 1;
		else r = m;
	}
	cout << l - 1;
}