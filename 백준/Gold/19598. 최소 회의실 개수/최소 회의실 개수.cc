#include <bits/stdc++.h>
using namespace std;

int N, l, r, res;
vector<pair<int, int>> meeting;

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		meeting.push_back({ l, r });
	}
	sort(meeting.begin(), meeting.end());

	for (auto& it : meeting) {
		tie(l, r) = it;
		while (!pq.empty() && pq.top() <= l) {
			pq.pop();
		}
		pq.push(r);
		res = max(res, (int)pq.size());
	}
	cout << res;
}