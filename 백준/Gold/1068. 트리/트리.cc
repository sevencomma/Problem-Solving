#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
bool visited[50];
int parent[50];
int node_all[50];

void func(int root) {
	int count = 0;
	visited[root] = true;
	for (auto& it : tree[root]) {
		if (!visited[it]) {
			visited[it] = true;
			func(it);
			count += node_all[it];
		}
	}
	if (count == 0)
		node_all[root] = 1;
	else
		node_all[root] = count;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, root, target;
	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		if (t == -1)
			root = i;
		else {
			tree[i].push_back(t);
			tree[t].push_back(i);
		}
		parent[i] = t;
	} cin >> target;
	if (root == target) {
		cout << 0;
		return 0;
	}
	func(root);
	int ans = node_all[root] - node_all[target];
	bool is_leaf = true;
	for (int i = 0; i < N; i++)
		if (parent[i] == target)
			is_leaf = false;
	if (is_leaf) {
		for (int i = 0; i < N; i++) {
			if (i == target)
				continue;
			if (parent[i] == parent[target])
				is_leaf = false;
		}
	}
	if (is_leaf)
		ans++;
	cout << ans;
}