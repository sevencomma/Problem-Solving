#include <bits/stdc++.h>
using namespace std;

int N, X, P;
vector<int> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> X >> P;
	if (N == 0 && P > 0) {
		cout << 1;
		return 0;
	}
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.rbegin(), arr.rend());

	map<int, int> rank;
	for (int i = 0; i < N; i++) {
		if (i > 0 && arr[i - 1] == arr[i])
			continue;
		rank[arr[i]] = i + 1;
	}

	int idx = 0, ans = -1;
	while (idx < P && idx < N) {
		if (arr[idx] < X) {
			if (ans == -1)
				ans = rank[arr[idx]];
			break;
		}
		else if (arr[idx] == X) {
			ans = rank[arr[idx]];
		}

		idx++;
	}

	if (idx == N) {
		if (P > N) {
			if (arr[N - 1] == X)
				ans = rank[arr[N - 1]];
			else
				ans = N + 1;
		}
		else if (P == N) {
			ans = -1;
		}
	}

	cout << ans;
}