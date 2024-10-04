#include <bits/stdc++.h>
using namespace std;

int D[101][101];
int N, M, a, b, c;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i == j)
				D[i][j] = 0;
			else
				D[i][j] = INT_MAX / 3;
		}
	for (int k = 0; k < M; k++) {
		cin >> a >> b >> c;
		D[a][b] = min(D[a][b], c);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (D[i][j] == INT_MAX / 3)
				cout << 0 << ' ';
			else
				cout << D[i][j] << ' ';
		cout << endl;
	}
}