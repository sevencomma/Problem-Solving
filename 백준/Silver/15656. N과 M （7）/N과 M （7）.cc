#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> numbers;
int arr[10];

void back_tracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << numbers[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[cnt] = i;
		back_tracking(cnt + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	numbers.resize(n);
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	sort(numbers.begin(), numbers.end());
	back_tracking(0);
}