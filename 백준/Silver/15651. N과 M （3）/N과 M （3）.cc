#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void back_tracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[cnt] = i;
		back_tracking(cnt + 1);
	}
}

int main(void) {
	cin >> n >> m;
	back_tracking(0);
}