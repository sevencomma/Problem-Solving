#include <bits/stdc++.h>
using namespace std;

long long count_made[201][201];
int N, K;

int main(void) {
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
		count_made[1][i] = 1;

	for (int i = 2; i <= K; i++)
		for (int j = 0; j <= N; j++)
			for (int c = 0; c <= j; c++)
				count_made[i][j]  = (count_made[i][j] + count_made[i - 1][c]) % 1000000000;

	cout << count_made[K][N] % 1000000000;
}