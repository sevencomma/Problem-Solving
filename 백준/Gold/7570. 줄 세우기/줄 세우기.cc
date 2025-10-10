#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
int cache[1000001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	int maxCnt = 0;
	for (int i = 1; i <= N; i++) {
		int num = arr[i];
		if (cache[num - 1] == 0)
			cache[num] = 1;
		else
			cache[num] = cache[num - 1] + 1;
		maxCnt = max(maxCnt, cache[num]);
	}

	cout << N - maxCnt << '\n';
}