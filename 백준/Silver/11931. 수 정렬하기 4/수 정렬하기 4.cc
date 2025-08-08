#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.rbegin(), arr.rend());
	for (auto& it : arr)
		cout << it << '\n';
}