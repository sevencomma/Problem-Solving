#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> input;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	input.resize(N);
	for (int i = 0; i < N; i++)
		cin >> input[i].first >> input[i].second;
	sort(input.begin(), input.end());

	int day, weight;
	for (auto& it : input) {
		tie(day, weight) = it;
		pq.push(weight);
		if (pq.size() > day)
			pq.pop();
	}

	int res = 0;
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
	cout << res;
}