#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, K, t, d;
ll res;

vector<int> takenTime[200001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> t >> d;
		takenTime[d].push_back(t);
	}

	int cnt = 0;
	for (auto& it : takenTime[cnt])
		pq.push(it);

	while (!pq.empty() && cnt < K) {
		res += pq.top();
		pq.pop();
		cnt++;

		for (auto& it : takenTime[cnt])
			pq.push(it);
	}

	if (pq.empty() && cnt < K)
		cout << "IMPOSSIBLE";
	else
		cout << res;
}