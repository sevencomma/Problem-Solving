#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N, L, res = 0;
	cin >> N >> L;
	int road[100][100] = { 0, };
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> road[i][j];

	for (int i = 0; i < N; i++) {
		int prev = road[i][0];
		int count = 1;
		bool can_ = true;
		for (int j = 1; j < N; j++) {	// road[i][0] --> road[i][N-1]
			if (road[i][j] == prev) {
				count++;
			}
			else if (road[i][j] == prev - 1) {
				prev--;
				int k;
				for (k = 0; k < L; k++) {
					if (j + k >= N || road[i][j + k] != prev) {
						can_ = false;
						break;
					}
				}
				j += (k - 1);
				count = 0;
			}
			else if (road[i][j] == prev + 1) {
				if (count < L) {
					can_ = false;
					break;
				}
				count = 1;
				prev++;
			}
			else {
				can_ = false;
				break;
			}

		}

		if (can_)
			res++;

		prev = road[0][i];
		count = 1;
		can_ = true;
		for (int j = 1; j < N; j++) {	// road[0][i] --> road[N-1][i]
			if (road[j][i] == prev) {
				count++;
			}
			else if (road[j][i] == prev - 1) {
				prev--;
				int k;
				for (k = 0; k < L; k++) {
					if (j + k >= N || road[j + k][i] != prev) {
						can_ = false;
						break;
					}
				}
				j += (k - 1);
				count = 0;
			}
			else if (road[j][i] == prev + 1) {
				if (count < L) {
					can_ = false;
					break;
				}
				count = 1;
				prev++;
			}
			else {
				can_ = false;
				break;
			}
		}
		if (can_)
			res++;

	}
	cout << res;
}