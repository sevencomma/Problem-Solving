#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[500000];
int Rank[500000];

void Link(int x, int y) {
	if (Rank[x] > Rank[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (Rank[x] == Rank[y])
			Rank[y] = Rank[x] + 1;
	}
}

int Find(int x) {
	if (parent[x] != x) {
		parent[x] = Find(parent[x]);
	}
	return parent[x];
}

void Union(int x, int y) {
	Link(Find(x), Find(y));
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		parent[i] = i;
	int a, b, res = 0;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		if (Find(a) == Find(b)) {
			res = i;
			break;
		}
		Union(a, b);
	}
	cout << res;
}