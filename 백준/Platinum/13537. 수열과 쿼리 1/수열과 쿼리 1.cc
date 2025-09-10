#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, k;
vector<int> arr;
vector<vector<int>> tree;

void init(int node, int start, int end) {
	if (start == end) {
		tree[node].push_back(arr[start]);
		return;
	}

	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());

	merge(tree[node * 2].begin(), tree[node * 2].end(), 
			tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
			tree[node].begin());
}

int query(int node, int start, int end, int left, int right, int k) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right)
		return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right, k) +
		query(node * 2 + 1, mid + 1, end, left, right, k);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	tree.resize(N * 4);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	init(1, 0, N - 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> k;
		cout << query(1, 0, N - 1, x - 1, y - 1, k) << '\n';
	}
}