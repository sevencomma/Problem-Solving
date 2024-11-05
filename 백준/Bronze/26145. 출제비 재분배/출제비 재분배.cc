#include <bits/stdc++.h>
using namespace std;

int N, M, t;
int m[2001];

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> m[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N + M; j++) {
			cin >> t;
			m[i] -= t;
			m[j] += t;
		}
	}
	for (int i = 1; i <= N + M; i++)
		cout << m[i] << ' ';
}