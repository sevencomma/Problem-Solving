#include <bits/stdc++.h>
using namespace std;

int N, D = INT_MAX, L, R;
vector<int> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int l = 0, r = N - 1;

	while (l < r) {
		if (D > abs(arr[l] + arr[r])) {
			D = abs(arr[l] + arr[r]);
			L = l;
			R = r;
		}
		if (arr[l] + arr[r] < 0)
			l++;
		else
			r--;
	}
	cout << arr[L] << ' ' << arr[R];
}