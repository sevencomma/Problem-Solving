#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> sensor;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	sensor.resize(N);
	for (int i = 0; i < N; i++)
		cin >> sensor[i];
	sort(sensor.begin(), sensor.end());
	priority_queue<int> pq;
	for (int i = 1; i < N; i++) {
		pq.push(sensor[i] - sensor[i - 1]);
	}

	for (int i = 0; !pq.empty() && i < (K - 1); i++)
		pq.pop();
	int res = 0;
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
	cout << res;
}