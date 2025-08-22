#include <bits/stdc++.h>
using namespace std;

int T, N;

struct point {
	int cost, idx;
};

struct cmp {
	bool operator() (point& a, point& b) const {
		if (a.cost != b.cost)
			return a.cost < b.cost;
		return a.idx > b.idx;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		priority_queue<point, vector<point>, cmp> pq;
		for (int i = 0; i < N; i++)
			pq.push({ arr[i], i });

		vector<int> has;
		long long res = 0;
		for (int i = 0; i < N; i++) {
			if (!pq.empty() && pq.top().idx > i) { // 사
				has.push_back(arr[i]);
			}
			else {	// 팔아 or 냅둬
				for (auto& it : has)
					res += arr[i] - it;
				has.clear();
				while (!pq.empty() && pq.top().idx <= i)
					pq.pop();
			}
		}
		cout << res << '\n';
	}
}