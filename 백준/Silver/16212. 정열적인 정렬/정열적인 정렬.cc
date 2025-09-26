#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (auto& it : arr)
		cout << it << ' ';
}