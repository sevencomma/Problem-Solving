#include <bits/stdc++.h>
using namespace std;

int n, m = 6;
int arr[15];
int isused[15];
vector<int> numbers;

void back_tracking(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < 6; i++)
			cout << numbers[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i < n; i++) {
		if (!isused[i]) {
			arr[cnt] = i;
			isused[i] = 1;
			back_tracking(i + 1, cnt + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		numbers.resize(n);
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		back_tracking(0, 0);
		cout << "\n";
	}
}