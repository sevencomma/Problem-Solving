#include <bits/stdc++.h>
using namespace std;

int N, t, s;
vector<pair<int, int>> tasks;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> s;
		tasks.push_back({ s, t });
	}

	sort(tasks.rbegin(), tasks.rend());

	int cur = tasks[0].first;
	int idx = 0;
	while (cur >= 0 && idx < N) {
		tie(s, t) = tasks[idx];
		
		if (cur > s)
			cur = s;

		cur -= t;
		idx++;
	}

	cout << ((cur < 0) ? -1 : cur);
}