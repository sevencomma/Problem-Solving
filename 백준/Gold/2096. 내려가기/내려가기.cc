#include <bits/stdc++.h>
using namespace std;

int N;
int cache[3];
int minScore[2][3];
int maxScore[2][3];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cache[0] >> cache[1] >> cache[2];

		minScore[1][0] = min(minScore[0][0], minScore[0][1]) + cache[0];
		minScore[1][1] = min(minScore[0][0], min(minScore[0][1], minScore[0][2])) + cache[1];
		minScore[1][2] = min(minScore[0][1], minScore[0][2]) + cache[2];

		maxScore[1][0] = max(maxScore[0][0], maxScore[0][1]) + cache[0];
		maxScore[1][1] = max(maxScore[0][0], max(maxScore[0][1], maxScore[0][2])) + cache[1];
		maxScore[1][2] = max(maxScore[0][1], maxScore[0][2]) + cache[2];

		minScore[0][0] = minScore[1][0];
		minScore[0][1] = minScore[1][1];
		minScore[0][2] = minScore[1][2];

		maxScore[0][0] = maxScore[1][0];
		maxScore[0][1] = maxScore[1][1];
		maxScore[0][2] = maxScore[1][2];
	}

	cout << max(maxScore[0][0], max(maxScore[0][1], maxScore[0][2])) << ' ';
	cout << min(minScore[0][0], min(minScore[0][1], minScore[0][2]));
}