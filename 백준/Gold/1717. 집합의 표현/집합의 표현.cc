#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1000001];
int rank_[1000001];

void Link(int x, int y) {
	if (rank_[x] > rank_[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (rank_[x] == rank_[y])
			rank_[y] = rank_[x] + 1;
	}
}

int Find_set(int x) {
	if (parent[x] != x)
		parent[x] = Find_set(parent[x]);
	return parent[x];
}

void Union(int x, int y) {
	Link(Find_set(x), Find_set(y));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			Union(b, c);
		}
		else {
			if (Find_set(b) == Find_set(c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}