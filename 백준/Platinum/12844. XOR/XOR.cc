#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, k;
vector<int> arr, tree, lazy;

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		if ((end - start + 1) % 2)
			tree[node] ^= lazy[node];

		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int start, int end, int range_start, int range_end, int k) {
	update_lazy(node, start, end);
	if (start > range_end || end < range_start) return;
	if (range_start <= start && end <= range_end) {
		if ((end - start + 1) % 2)
			tree[node] ^= k;
		if (start != end) {
			lazy[node * 2] ^= k;
			lazy[node * 2 + 1] ^= k;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, range_start, range_end, k);
	update_range(node * 2 + 1, mid + 1, end, range_start, range_end, k);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query_range(int node, int start, int end, int range_start, int range_end) {
	update_lazy(node, start, end);
	if (start > range_end || end < range_start) return 0;
	if (range_start <= start && end <= range_end) return tree[node];

	int mid = (start + end) / 2;
	return query_range(node * 2, start, mid, range_start, range_end) ^
		query_range(node * 2 + 1, mid + 1, end, range_start, range_end);
}

void build(vector<int>& arr, int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start - 1];
		return;
	}
	int mid = (start + end) / 2;
	build(arr, node * 2, start, mid);
	build(arr, node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	tree.resize(N * 4, 0);
	lazy.resize(N * 4, 0);

	build(arr, 1, 1, N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> k;
			update_range(1, 1, N, b + 1, c + 1, k);
		}
		else {
			cout << query_range(1, 1, N, b + 1, c + 1) << '\n';
		}
	}
}