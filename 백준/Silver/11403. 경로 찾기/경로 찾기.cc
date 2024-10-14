#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, temp; cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 0)
				dp[i][j] = 123456789;
			else
				dp[i][j] = temp;
		}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 123456789)
				cout << 0 << ' ';
			else
				cout << 1 << ' ';
		}
		cout << '\n';
	}
}