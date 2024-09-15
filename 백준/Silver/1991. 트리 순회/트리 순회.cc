#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
unordered_map<char, vector<char>> tree;
void preorder(char start) {
	if (start == '.')
		return;
	cout << start;
	preorder(tree[start][0]);
	preorder(tree[start][1]);
}
void inorder(char start) {
	if (start == '.')
		return;
	inorder(tree[start][0]);
	cout << start;
	inorder(tree[start][1]);
}
void postorder(char start) {
	if (start == '.')
		return;
	postorder(tree[start][0]);
	postorder(tree[start][1]);
	cout << start;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	tree['.'] = {};
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back(b);
		tree[a].push_back(c);
	}
	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A'); cout << "\n";
}