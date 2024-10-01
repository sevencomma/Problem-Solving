#include <bits/stdc++.h>
using namespace std;

struct point {
	int m, v;

	bool operator < (point a) const {
		return v < a.v;
	}
};

bool compare(point a, point b) {
	return a.m < b.m;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<point> boseok;
	vector<int> backpack(K);

	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		boseok.push_back({ m, v });
	}
	for (int i = 0; i < K; i++)
		cin >> backpack[i];

	sort(boseok.begin(), boseok.end(), compare);
	sort(backpack.begin(), backpack.end());

	long long sum = 0;
	priority_queue<point> q;
	int index = 0;
	for (int i = 0; i < K; i++) {
		int size = backpack[i];

		while (index < N && size >= boseok[index].m) {
			q.push(boseok[index]);
			index++;
		}
		if (q.empty())
			continue;
		point cur = q.top();
		q.pop();
		sum += cur.v;
	}
	cout << sum;
}