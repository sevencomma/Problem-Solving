#include <bits/stdc++.h>
using namespace std;

#define INF 123456789

int N;
string seq;
int cachePal[2500][2500];
int cacheAns[2500];

int dpPal(int l, int r) {
	if (l == r) return cachePal[l][r] = 1;
	if (l + 1 == r && seq[l] == seq[r])
		return cachePal[l][r] = 1;

	int& ret = cachePal[l][r];
	if (ret != -1) return ret;

	ret = 0;
	if (seq[l] == seq[r] && dpPal(l + 1, r - 1) == 1)
		ret = 1;
	return ret;
}

int dpAns(int idx) {
	if (idx >= N) return 0;

	int& ret = cacheAns[idx];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = idx; i < N; i++) {
		if (dpPal(idx, i) == 1)
			ret = min(ret, dpAns(i + 1) + 1);
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(cachePal, -1, sizeof(cachePal));
	memset(cacheAns, -1, sizeof(cacheAns));
	cin >> seq;
	N = seq.length();
	dpPal(0, N - 1);
	cout << dpAns(0);
}
