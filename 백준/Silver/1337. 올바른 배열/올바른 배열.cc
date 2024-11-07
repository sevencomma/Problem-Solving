#include <bits/stdc++.h>
using namespace std;

int n, res = 5, cnt = 1;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	sort(seq.begin(), seq.end());
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				if (i + j < n && seq[i + j] == seq[i] + k)
					cnt++;
		res = min(res, 5 - cnt);
		cnt = 1;
	} cout << res;
}