#include <bits/stdc++.h>
using namespace std;

struct info {
	int p, f, s, v, c;
};

int N, mp, mf, ms, mv;
vector<info> arr;

int ans = 1e9;
vector<int> res;

void solve(int idx, int cp, int cf, int cs, int cv, int cost, vector<int> cur) {
	if (cp >= mp && cf >= mf && cs >= ms && cv >= mv) {
		if (ans > cost) {
			ans = cost;
			res = cur;
		}
		if (ans == cost) {
			if (res > cur)
				res = cur;
		}
		return;
	}
	if (cost > ans || idx == N) return;

	solve(idx + 1, cp, cf, cs, cv, cost, cur);
	cur.push_back(idx + 1);
	solve(idx + 1, cp + arr[idx].p, cf + arr[idx].f, cs + arr[idx].s, cv + arr[idx].v, cost + arr[idx].c, cur);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> mp >> mf >> ms >> mv;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
	}	
	solve(0, 0, 0, 0, 0, 0, {});
	cout << (ans == 1e9 ? -1 : ans) << "\n";
	if (ans != 1e9) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
	}
}