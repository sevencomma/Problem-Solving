#include <bits/stdc++.h>
using namespace std;

int n;
int num[1001];
int dp[1001];
int parent[1001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					parent[i] = j;
				}
			}
		}
	}
	
	int res = 0, index;
	for (int i = 0; i < n; i++) {
		if (res < dp[i]) {
			res = dp[i];
			index = i;
		}
	}
	cout << res << '\n';
	stack<int> seq;
	while (parent[index] != index) {
		seq.push(index);
		index = parent[index];
	}
	seq.push(index);

	while (!seq.empty()) {
		cout << num[seq.top()] << ' ';
		seq.pop();
	}
}