#include <bits/stdc++.h>
using namespace std;

int N, x, res;
vector<int> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1])
			continue;
		res += arr[i] - (arr[i + 1] - 1);
		arr[i] = arr[i + 1] - 1;
	}
	cout << res;
}