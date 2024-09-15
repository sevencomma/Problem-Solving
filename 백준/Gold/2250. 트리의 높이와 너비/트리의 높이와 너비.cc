#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
unordered_map<int, vector<int>> tree;
vector<int> sequence;

void inorder(int start) {
	if (start == -1)
		return;
	inorder(tree[start][0]);
	sequence.push_back(start);
	inorder(tree[start][1]);
}

unordered_map<int, vector<int>> layer;
void inorder_layer(int start, int cnt) {
	if (start == -1)
		return;
	inorder_layer(tree[start][0], cnt + 1);
	layer[cnt].push_back(start);
	inorder_layer(tree[start][1], cnt + 1);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<vector<int>> find_root(N + 1);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back(b);
		tree[a].push_back(c);

		if (b != -1)
			find_root[b].push_back(a);
		if (c != -1)
			find_root[c].push_back(a);
	}
	int root = 1;
	while (!find_root[root].empty()) {
		root = find_root[root][0];
	}
	unordered_map<int, int> node_index;
	inorder(root);

	for (int i = 0; i < sequence.size(); i++)
		node_index[sequence[i]] = i;
	inorder_layer(root, 1);
	int level = -1, distance = -1;
	int k = 1;
	while (!layer[k].empty()) {
		if (distance < node_index[layer[k][layer[k].size() - 1]] - node_index[layer[k][0]] + 1) {
			level = k;
			distance = node_index[layer[k][layer[k].size() - 1]] - node_index[layer[k][0]] + 1;
		}
		k++;
	}
	cout << level << ' ' << distance;
}