#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
vector<int> arr;
unordered_map<int, bool> checked;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int res = 1;
	for (auto& it : arr) {
		if (it > res) break;
		res += it;
	}
	cout << res;
}