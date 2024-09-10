#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void back_tracking(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; i++) {
		if (!isused[i]) {
			arr[cnt] = i;
			isused[i] = 1;
			back_tracking(i + 1, cnt + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	cin >> n >> m;
	back_tracking(1, 0);
}