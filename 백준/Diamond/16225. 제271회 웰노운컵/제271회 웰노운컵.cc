#include <bits/stdc++.h>
using namespace std;

struct point {
	int a, b;
};

bool compare(point& x, point& y) {
	return x.b < y.b;
}

int N;
vector<point> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i].a;
	for (int i = 0; i < N; i++) cin >> arr[i].b;

	sort(arr.begin(), arr.end(), compare);

	priority_queue<int> pq;
	long long res = 0;
	res += arr[0].a;

	for (int i = 1; i < N - 1; i += 2) {
		pq.push(arr[i].a);
		pq.push(arr[i + 1].a);

		res += pq.top();
		pq.pop();
	}
	cout << res;
}