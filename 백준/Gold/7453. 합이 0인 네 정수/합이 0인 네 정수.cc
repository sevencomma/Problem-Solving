#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll A[4000], B[4000], C[4000], D[4000];
ll res;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	vector<ll> ab, cd;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			ab.push_back(A[i] + B[j]);
			cd.push_back(C[i] + D[j]);
		}

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	for (auto& it : ab) {
		// cd에서 -it인 범위 = [L, R]
		int L = -1, R = -1;

		int l = 0, r = N * N, mid;
		while (l < r) {
			mid = (l + r) / 2;

			if (cd[mid] < -it)
				l = mid + 1;
			else if (cd[mid] == -it)
				r = mid;
			else if (cd[mid] >= -it)
				r = mid - 1;
		}
		if (cd[l] != -it)
			continue;

		L = l;

		l = 0, r = N * N - 1;
		while (l < r) {
			mid = (l + r + 1) / 2;

			if (cd[mid] < -it)
				l = mid + 1;
			else if (cd[mid] == -it)
				l = mid;
			else if (cd[mid] > -it)
				r = mid - 1;
		}
		if (cd[l] != -it)
			continue;
		R = l;

		res += (R - L + 1);
	}

	cout << res;
}