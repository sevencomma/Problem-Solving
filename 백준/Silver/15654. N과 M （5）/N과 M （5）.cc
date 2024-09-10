#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
int arr[10];
int isused[10];

void back_tracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << nums[arr[i]] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[cnt] = i;
			isused[i] = 1;
			back_tracking(cnt + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	back_tracking(0);
}