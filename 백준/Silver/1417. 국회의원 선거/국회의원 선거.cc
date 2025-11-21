#include <bits/stdc++.h>
using namespace std;

int N, dasom;
priority_queue<int> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> dasom;
	for (int i = 0; i < N - 1; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int cnt = 0;
	while (!pq.empty() && pq.top() >= dasom) {
		int x = pq.top();
		pq.pop();
		x--;
		dasom++;
		pq.push(x);
		cnt++;
	}
	cout << cnt;
}