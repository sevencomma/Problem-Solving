#include <bits/stdc++.h>
using namespace std;

char c;
int N, K, x, y;
vector<int> arr;
vector<int> tree;

int init(vector<int>& arr, int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];

	int mid = (left + right) / 2;
	return tree[node] = init(arr, left, mid, node * 2) * init(arr, mid + 1, right, node * 2 + 1);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (right < nodeLeft || left > nodeRight) return 1;
	if (left <= nodeLeft && nodeRight <= right) return tree[node];

	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, node * 2, nodeLeft, mid) *
		query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

int update(int index, int newVal, int node, int nodeLeft, int nodeRight) {
	if (index < nodeLeft || index > nodeRight) return tree[node];
	if (nodeLeft == nodeRight) return tree[node] = newVal;

	int mid = (nodeLeft + nodeRight) / 2;
	return tree[node] = update(index, newVal, node * 2, nodeLeft, mid) *
		update(index, newVal, node * 2 + 1, mid + 1, nodeRight);
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N >> K;
		if (cin.eof()) break;
		arr.clear();
		tree.clear();
		tree.resize(N * 4);

		for (int i = 0; i < N; i++) {
			cin >> x;
			if (x < 0) arr.push_back(-1);
			else if (x == 0) arr.push_back(0);
			else arr.push_back(1);
		}
		init(arr, 0, N - 1, 1);

		for (int i = 0; i < K; i++) {
			cin >> c >> x >> y;
			if (c == 'C') {
				if (y < 0) y = -1;
				else if (y == 0) y = 0;
				else y = 1;
				update(x - 1, y, 1, 0, N - 1);
			}
			else {
				int ret = query(x - 1, y - 1, 1, 0, N - 1);
				switch (ret) {
				case -1: cout << '-'; break;
				case 0: cout << '0'; break;
				case 1: cout << '+'; break;
				}
			}
		}
		cout << '\n';
	}
}
