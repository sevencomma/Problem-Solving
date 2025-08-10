#include <bits/stdc++.h>
using namespace std;

int N, x, res;
priority_queue<int> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		pq.push(x);
	}
	
	while (pq.size() >= 3) {
		res += pq.top(); pq.pop();
		res += pq.top(); pq.pop();
		pq.pop();
	}
	while (!pq.empty()) {
		res += pq.top(); pq.pop();
	}
	cout << res;
}