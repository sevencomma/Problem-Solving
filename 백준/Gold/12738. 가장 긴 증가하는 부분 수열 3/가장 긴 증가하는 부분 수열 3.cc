#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> LIS;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<int> seq(N);
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	LIS.push_back(seq[0]);

	for (int i = 1; i < N; i++) {
		if (LIS.back() < seq[i])
			LIS.push_back(seq[i]);
		else {
			int l = 0, r = LIS.size() - 1, m;

			while (l < r) {
				m = (l + r) / 2;
				if (LIS[m] < seq[i])
					l = m + 1;
				else
					r = m;
			}
			LIS[r] = seq[i];
		}
	} cout << LIS.size();
}