#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> num;
int isused[21];
int cnt;
void back_tracking(int c, int sum, int check) {
	if (sum == s && check != 0) {
		cnt++;
	}

	for (int i = c; i < n; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			back_tracking(i + 1, sum + num[i], check + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	cin >> n >> s;
	num.resize(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	back_tracking(0, 0, 0);
	cout << cnt;
}