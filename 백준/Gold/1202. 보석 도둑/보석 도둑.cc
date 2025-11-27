#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct dat {
	int m, v;
};

struct cmpV {
	bool operator() (dat& a, dat& b) {
		return a.v < b.v;
	}
};

bool cmpM(dat& a, dat& b) {
	return a.m < b.m;
}

int N, K, m, v, x;
vector<dat> boseok;
vector<int> backpack;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		boseok.push_back({m, v});
	}
	for (int i = 0; i < K; i++) {
		cin >> x;
		backpack.push_back(x);
	}

	sort(boseok.begin(), boseok.end(), cmpM);
	sort(backpack.begin(), backpack.end());

	priority_queue<dat, vector<dat>, cmpV> pq;
	int idx = 0;
	ll res = 0;

	for (int i = 0; i < K; i++) {
		int size = backpack[i];

		while (idx < N && boseok[idx].m <= size) {
			pq.push(boseok[idx]);
			idx++;
		}

		if (!pq.empty()) {
			res += pq.top().v;
			pq.pop();
		}
	}
	cout << res;
}