#include <bits/stdc++.h>
using namespace std;

int N, x;
vector<int> adjs[50];

int solve(int cur) {
	vector<int> childs;
	int ret = 0;

	for (auto& next : adjs[cur]) {
		childs.push_back(solve(next));
	}

	sort(childs.rbegin(), childs.rend());
	for (int i = 1; i <= childs.size(); i++) {
		ret = max(ret, childs[i - 1] + i);
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == -1) continue;
		adjs[x].push_back(i);
	}

	cout << solve(0);
}