#include <bits/stdc++.h>
using namespace std;

int N, M, x, res;
priority_queue<int> pq;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;

	long long cur = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;
		cur += x;
		pq.push(x);

		if (cur >= M) {
			cur -= 2 * pq.top();
			pq.pop();
			res++;
		}
	}

	cout << res;
}