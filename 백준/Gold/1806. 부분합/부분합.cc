#include <bits/stdc++.h>
using namespace std;

int N, S, sum;
int sequence[100000];


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> sequence[i];

	int res = INT_MAX;
	int left = 0, right = 0;
	sum = sequence[0];
	while (left <= right && right < N) {
		if (sum < S)
			sum += sequence[++right];
		else {
			res = min(res, right - left + 1);
			sum -= sequence[left++];
		}
	}
	if (res == INT_MAX)
		cout << 0;
	else
		cout << res;
}