#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
int N, x, a, b, c;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		pq.push(x);
	}

	a = pq.top(); pq.pop();
	b = pq.top(); pq.pop();
	c = pq.top(); pq.pop();

	while (!pq.empty() && a >= b + c) {
		a = b;
		b = c;
		c = pq.top(); pq.pop();
	}

	if (a >= b + c)
		cout << -1;
	else
		cout << a + b + c;
}
